/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "Defines.h"

//==============================================================================
MainComponent::MainComponent()

#if JUCE_PROJUCER_LIVE_BUILD
#endif
{

    // Make sure you set the size of the component after
    // you add any child components.
    
    fs = deviceManager.getAudioDeviceSetup().sampleRate;
    
    transportState = TransportState::Stopped;
    
    // Make sure that formatManager can read all basic audio file types.
    formatManager.registerBasicFormats();
    
    // Make the WavAudioFormat
    wavAudioFormat = std::make_unique<WavAudioFormat> ();
    
    // SourceFilePanel Creation
    initialSourceDirectoryPath = "~/Desktop/metamakerWavs/Source";
    initialDestinationDirectoryPath = "~/Desktop/metamakerWavs/Destination";
    
    sourceFilePanel  = std::make_unique<FileBrowserPanel> (GUIDefines::initialFileBrowserWidth,
                                                           GUIDefines::fileBrowserHeight,
                                                           initialSourceDirectoryPath);
    sourceFilePanel -> setTopLeftPosition (0, GUIDefines::mainWindowTopYCoordinate);
    sourceFilePanel -> setColour (FileBrowserComponent::ColourIds::filenameBoxBackgroundColourId, Colours::yellow);
    sourceFilePanel -> getFileBrowser() -> deselectAllFiles();
    
    // FileProperty Creation
    propertyPanel = std::make_unique<FileInfoPanel> (GUIDefines::initialFileInfoWidth,
                                                     GUIDefines::propertyPanelHeight);
    propertyPanel -> setTopLeftPosition (GUIDefines::initialFileBrowserWidth, GUIDefines::mainWindowTopYCoordinate);
    
    // FileInfoPanel creation
    destinationPanel = std::make_unique<FileBrowserPanel> (GUIDefines::initialFileBrowserWidth,
                                                           GUIDefines::fileBrowserHeight,
                                                           initialDestinationDirectoryPath);
    
    destinationPanel -> setTopLeftPosition (GUIDefines::initialFileBrowserWidth + GUIDefines::initialFileInfoWidth,
                                            GUIDefines::mainWindowTopYCoordinate);
    
    // Debug Button Panel
    buttonPanel = std::make_unique<ButtonPanel> (GUIDefines::initialButtonPanelWidth, GUIDefines::initialButtonPanelHeight);
    
    buttonPanel -> setTopLeftPosition (GUIDefines::initialFileBrowserWidth, GUIDefines::propertyPanelHeight - GUIDefines::initialButtonPanelHeight);
    
    // Waveform Panel
    waveformPanel  = std::make_unique<WaveformPanel>(512, formatManager, GUIDefines::universalWidth, 200);
    waveformPanel -> setTopLeftPosition(0, GUIDefines::fileBrowserHeight);
    
    settingsWindowPanel = std::make_unique<SettingsWindowPanel>(GUIDefines::settingsWindowWidth, GUIDefines::settingsWindowHeight);
    
    settingsWindow = std::make_unique<SettingsWindow>(GUIDefines::settingsWindowWidth, GUIDefines::settingsWindowHeight, "Settings", settingsWindowPanel.get());
    
    createSaveDataIfNecessary();
    startupPathNode = loadValueTree(getSaveFile(), true);
    
    // Log settings label in Value Tree
    settingsWindowPanel -> setLabeltext(startupPathNode.getProperty(startupPath_ID).toString());
    
    Logger::writeToLog(startupPath_XML.toString());
    startupPath_XML.setAttribute(startupPath_ID, startupPathNode.getProperty(startupPath_ID).toString());
    
    Logger::writeToLog(startupPath_XML.toString());
    
    // Set initial Directories
    sourceFilePanel -> setRoot (File (settingsWindowPanel -> getLabelText ()));
    
    // AddAndMakeVisibles
    addAndMakeVisible (*sourceFilePanel);
    addAndMakeVisible (*propertyPanel);
    addAndMakeVisible (*destinationPanel);
    addAndMakeVisible (*buttonPanel);
    addAndMakeVisible (*waveformPanel);
    
    // Set Size
    setSize (GUIDefines::universalWidth, GUIDefines::universalHeight);
    
    
    // LISTENERS
        // Add the listening functionality for the button.
    sourceFilePanel -> getFileBrowser () -> addListener(this);
    
    buttonPanel     -> getCopyButton ()  -> addListener(this);
    buttonPanel     -> getMoveButton ()  -> addListener(this);
    buttonPanel     -> getWriteAndCopyButton() -> addListener(this);
    buttonPanel     -> getreplaceMetadataButton() -> addListener(this);
    buttonPanel     -> getOpenSettingsButton()    -> addListener(this);
    
    buttonPanel     -> getTransportPlayButton()   -> addListener(this);
    buttonPanel     -> getTransportStopButton()   -> addListener(this);
    
    propertyPanel   -> getArtistLabel () -> addListener(this);
    propertyPanel   -> getFileNameLabel () -> addListener(this);
    propertyPanel   -> getDescriptionLabel () -> addListener(this);
    propertyPanel   -> getFileCreationDateLabel () -> addListener(this);
    
    settingsWindowPanel -> getSourcePathLabel () -> addListener(this);
    settingsWindowPanel -> getSourcePathLabel () -> addListener (sourceFilePanel.get());
    
    buttonPanel -> getTimerStartButton() -> addListener(this);
    buttonPanel -> getTimerStopButton() -> addListener(this);
    
    transportSource.addChangeListener(this);
    
    
    // Initial Refresh for the Filebrowsers
    sourceFilePanel -> getFileBrowser () -> refresh();
    destinationPanel -> getFileBrowser () -> refresh();
    
    
    // Initialize stringpairArray with keys and initial values;
    metadataInPanel = StringPairArray();
    metadataInPanel.set(Defines::originatorKey, "originator");
    metadataInPanel.set(Defines::originationDateKey, "date");
    metadataInPanel.set(Defines::descriptionKey, "description");
    
    // Some platforms require permissions to open input channels so request that here
    if (RuntimePermissions::isRequired (RuntimePermissions::recordAudio)
        && ! RuntimePermissions::isGranted (RuntimePermissions::recordAudio))
    {
        RuntimePermissions::request (RuntimePermissions::recordAudio,
                                     [&] (bool granted) { if (granted)  setAudioChannels (2, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
    }
    

}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    
    startupPathNode.setProperty(startupPath_ID, settingsWindowPanel -> getLabelText(), nullptr);
    saveValueTree(startupPathNode, getSaveFile(), true);
    
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()
    
    
    transportSource.prepareToPlay (samplesPerBlockExpected, sampleRate);
    
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{ 
    // Your audio-processing code goes here!

    // For more details, see the help for AudioProcessor::getNextAudioBlock()

    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
    
    if (readerSource.get() == nullptr)
    {
        bufferToFill.clearActiveBufferRegion();
        return;
    }
    
    // @TODO: Error here! Bad access! Look at this: https://docs.juce.com/master/tutorial_looping_audio_sample_buffer_advanced.html
    
    //transportSource.getNextAudioBlock (bufferToFill);
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

        transportSource.releaseResources();
    
    
    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    // You can add your drawing code here!

    
    
    
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}


// Override methods from ButtonListener
void MainComponent::buttonClicked(Button* button)
{
    
    if (button -> getButtonText() == "CopyButton") {
        copyFromSourceToDestination();
    }
    
    if (button -> getButtonText() == "MoveButton") {
        Logger::writeToLog("MoveButton Clicked! \n");
        moveFromSourceToDestination();
        
    }
    
    if (button -> getButtonText() == "WriteAndCopy") {
        Logger::writeToLog("Write and Copy!");
        
        for (int i = 0; i < sourceFilePanel ->getFileBrowser() ->getNumSelectedFiles(); i++) {
            
            File fileToCopy = sourceFilePanel -> getCurrentFile(i);
            
            File destinationFile = File (destinationPanel ->getFullPath() + "/" + fileToCopy.getFileName());
            
            std::unique_ptr<AudioFormatReader> reader (formatManager.createReaderFor (fileToCopy));
            
            if (reader != nullptr)
            {
                //File file  = sourceFilePanel -> getCurrentFile();
                std::shared_ptr <StringPairArray> metaDataValues = std::make_shared<StringPairArray> (reader -> metadataValues);
                // metaDataValues -> set("bwav description", editingPanel -> getTextFromEditingLabel() );
                metaDataValues -> set("bwav description", "Did it work ? ");
                
                
                updateFilePropertyPanel();
                
                bool hasBeenCopied = fileToCopy.copyFileTo(destinationFile);
                if (hasBeenCopied)
                {
                    Logger::writeToLog("Worked! for " + fileToCopy.getFileName() + "\n");
                }
                else
                {
                    Logger::writeToLog("Didn't work for" + fileToCopy.getFileName() + "\n");
                }
                destinationPanel -> refreshFileBrowser();
                wavAudioFormat -> replaceMetadataInFile(destinationFile, *metaDataValues);

            }
            
            else
            {
                Logger::writeToLog("Error");
                
            }
        }
       
    }
    
    if (button -> getButtonText() == "Replace")
    {
        for (int i = 0; i < sourceFilePanel ->getFileBrowser() ->getNumSelectedFiles(); i++) {
            
            File fileToEdit = sourceFilePanel -> getCurrentFile(i);
            
            std::unique_ptr<AudioFormatReader> reader (formatManager.createReaderFor ( fileToEdit ));
            
            if (reader != nullptr)
            {
                
                //File file  = sourceFilePanel -> getCurrentFile();
                std::shared_ptr <StringPairArray> metaDataValues = std::make_shared<StringPairArray> (reader -> metadataValues);
                // metaDataValues -> set("bwav description", editingPanel -> getTextFromEditingLabel() );
                wavAudioFormat -> replaceMetadataInFile(fileToEdit, metadataInPanel);
                Logger::writeToLog("Worked!");
                
                updateFilePropertyPanel();
                
                
                
            }
            
            else
            {
                Logger::writeToLog("Error");
                
            }
        }
    }
    
    
#pragma mark OpenSettings
    if (button -> getButtonText() == "Open Settings")
    {
        if (settingsWindow -> getVisibilityState() == false)
        {
            settingsWindow -> setVisible(true);
            settingsWindow -> setVisibiltyState(true);
        }
        else
        {
            settingsWindow -> setVisible(false);
            settingsWindow -> setVisibiltyState(false);
        }
        
    }
    
#pragma mark PlayButton
    //on play
    if (button -> getButtonText() == "Play")
    {

        File file = sourceFilePanel -> getCurrentFile();
        auto* reader = formatManager.createReaderFor(file);
        
        if (reader != nullptr) {
            
            
            
            if (waveformPanel -> getRectangleWidth() != 0)
            {
                Logger::writeToLog((String) reader -> lengthInSamples);
                
                float rectangleWidth = waveformPanel -> getRectangleWidth();
                float totalWidth = waveformPanel -> getWidth();
                float rectangleStartPosition = waveformPanel -> getRectangleStartPosition();
                
                auto lengthInSamples = reader -> lengthInSamples;
                
                Logger::writeToLog((String)rectangleWidth);
                Logger::writeToLog((String)totalWidth);
                Logger::writeToLog((String)lengthInSamples);
                
                playbackTimeSelectionRange = (rectangleWidth / totalWidth) * lengthInSamples;
                playbackStartPosition = (rectangleStartPosition / totalWidth) * lengthInSamples;

                subsectionReader = std::make_unique<AudioSubsectionReader>(reader, (int) playbackStartPosition, (int) playbackTimeSelectionRange, false);

                std::unique_ptr<AudioFormatReaderSource> newSource (new AudioFormatReaderSource (subsectionReader.get(), false));

                transportSource.setSource (newSource.get());
                Logger::writeToLog((String) transportSource.getTotalLength());
                readerSource.reset (newSource.release());
                Logger::writeToLog((String) transportSource.getTotalLength());
                delete reader;
                
            }

            
        }
        
        
        Logger::writeToLog((String) transportSource.getTotalLength());
        changeState (TransportState::Starting);
        
    }
    
#pragma mark StopButton
    
    if (button -> getButtonText() == "Stop")
    {
        changeState (TransportState::Stopping);
    }
    
    if (button -> getButtonText() == "Start Timer")
    {
        if (! Timer::isTimerRunning()) {
            startTimer(1000);
        }
        
        Logger::writeToLog("Timer started");
    }
    
    if (button -> getButtonText() == "Stop Timer")
    {
        stopTimer();
        
        
        Logger::writeToLog("Timer stopped");
    }
    
    
    
    
}



// Timer Callback override
void MainComponent::timerCallback()
{
    Logger::writeToLog("Timmer Running!");
    Logger::writeToLog("Rectangle Size: " + (String) waveformPanel -> getRectangleWidth());
    
}



// Override methods from FileBrowserListener
void MainComponent::selectionChanged ()
{
    updateFilePropertyPanel();
    File file = sourceFilePanel -> getCurrentFile();
    
    
    
    if (sourceFilePanel -> getNumSelectedFiles() == 0 || sourceFilePanel -> isCurrentlySelectedFileDirectory())
    {
        propertyPanel -> disableLabelEditing();
    }
    else
    {
        propertyPanel -> enableLabelEditing();
    }
    
    if (file.existsAsFile())
    {
        
        auto* reader = formatManager.createReaderFor (file);
        
        if (reader != nullptr)
        {
            
            std::unique_ptr<AudioFormatReaderSource> newSource (new AudioFormatReaderSource (reader, true));
            waveformPanel -> thumbnail.clear();
            waveformPanel -> thumbnail.setSource(new FileInputSource(file));
            
            transportSource.setSource (newSource.get(), 0, nullptr, reader->sampleRate);
            buttonPanel -> getTransportPlayButton() -> setEnabled (true);
            
            readerSource.reset (newSource.release());
            
        }
    }
    
    if (file.isDirectory()) {
        waveformPanel -> thumbnail.clear();
    }
    
}

void MainComponent::fileClicked(const File &file, const MouseEvent &e)
{

}

void MainComponent::fileDoubleClicked(const File &file)
{

}

void MainComponent::browserRootChanged(const File &newBrowserRoot)
{
    sourceFilePanel -> getFileBrowser() -> deselectAllFiles();
}

// Override functions from LabelListener

void MainComponent::labelTextChanged(Label *labelThatHasChanged)
{
    if (labelThatHasChanged == propertyPanel -> getArtistLabel() ||
        labelThatHasChanged == propertyPanel -> getFileNameLabel() ||
        labelThatHasChanged == propertyPanel -> getFileCreationDateLabel() ||
        labelThatHasChanged == propertyPanel -> getDescriptionLabel())
    {
        metadataInPanel.set(Defines::originatorKey, propertyPanel -> getArtistLabelText());
        metadataInPanel.set(Defines::originationDateKey, propertyPanel -> getFileCreationDateLabeltext());
        metadataInPanel.set(Defines::descriptionKey, propertyPanel -> getDescriptionLabelText());
        Utilites::printMetadata(metadataInPanel);
    }
    
    if (labelThatHasChanged == settingsWindowPanel -> getSourcePathLabel())
    {
        Logger::writeToLog("SettingsWindow panel source path Changed!");
        startupPathNode.setProperty(startupPath_ID, settingsWindowPanel -> getLabelText(), nullptr);
        Logger::writeToLog(startupPathNode.getProperty(startupPath_ID).toString());
    }
}

void MainComponent::editorShown (Label* , TextEditor &)
{
    Logger::writeToLog ("EditorShown! \n");
}

void MainComponent::editorHidden (Label *, TextEditor &)
{
    Logger::writeToLog ("Editor Hidden! \n");
    metadataInPanel.set(Defines::descriptionKey, propertyPanel -> getDescriptionLabelText());
    metadataInPanel.set(Defines::originatorKey, propertyPanel -> getArtistLabelText());
    metadataInPanel.set(Defines::originationDateKey, propertyPanel -> getFileCreationDateLabeltext());
    
    
    for (int i = 0; i < sourceFilePanel ->getFileBrowser() ->getNumSelectedFiles(); i++)
    {
        
        File fileToEdit = sourceFilePanel -> getCurrentFile(i);
        
        std::unique_ptr<AudioFormatReader> reader (formatManager.createReaderFor ( fileToEdit ));
        
        if (reader != nullptr)
        {
            
            //File file  = sourceFilePanel -> getCurrentFile();
            std::shared_ptr <StringPairArray> metaDataValues = std::make_shared<StringPairArray> (reader -> metadataValues);
            // metaDataValues -> set("bwav description", editingPanel -> getTextFromEditingLabel() );
            wavAudioFormat -> replaceMetadataInFile(fileToEdit, metadataInPanel);
            Logger::writeToLog("Worked!");
            
            updateFilePropertyPanel();
            
            
            
        }
    }
}


void MainComponent::changeListenerCallback(juce::ChangeBroadcaster *source)
{
    if (source == &transportSource) {
        
        if (transportSource.isPlaying())
        {
            changeState (TransportState::Playing);
        }
        
        else
        {
            changeState (TransportState::Playing);
        }
        
    }
}

void MainComponent::changeState (TransportState newState)
{
    if (transportState != newState)
    {
        transportState = newState;
        
        switch (transportState)
        {
            case TransportState::Stopped:                           // [3]
                buttonPanel ->getTransportStopButton() -> setEnabled (false);
                buttonPanel ->getTransportPlayButton() -> setEnabled (true);
                transportSource.setPosition (0.0);
                
                break;
                
            case TransportState::Starting:                          // [4]
                buttonPanel -> getTransportPlayButton() -> setEnabled (false);
                transportSource.start();
                
                
                break;
                
            case TransportState::Playing:                           // [5]
                buttonPanel -> getTransportStopButton() ->setEnabled (true);
                break;
                
            case TransportState::Stopping:                          // [6]
                transportSource.stop();
                break;
        }
    }
}


// Custom Methods

// Updates the FileInfoPanel
void MainComponent::updateFilePropertyPanel()
{
    StringPairArray metaDataValues = getMetadataFromFile();
    
    if (metaDataValues != Defines::emptyMetaDataFields || ! sourceFilePanel -> isCurrentlySelectedFileDirectory())
    {
        
        propertyPanel -> setDescriptionLabelText         (metaDataValues.getValue (Defines::descriptionKey, ""));
        propertyPanel -> setArtistLabelText              (metaDataValues.getValue (Defines::originatorKey, ""));
        propertyPanel -> setFileCreationDateLabelText    (metaDataValues.getValue (Defines::originationDateKey, ""));
        propertyPanel -> setFileNameLabelText            (sourceFilePanel -> getCurrentFileName());
    }
    else
    {
        propertyPanel -> setDescriptionLabelText         ("");
        propertyPanel -> setArtistLabelText              ("");
        propertyPanel -> setFileCreationDateLabelText    ("");
        propertyPanel -> setFileNameLabelText            ("");
    }
}

StringPairArray MainComponent::getMetadataFromFile()
{
    /*
     Retrieves the metadata from the file that's currently selected in the fileBrowser.
     */
    
    std::unique_ptr<AudioFormatReader> reader (formatManager.createReaderFor ( sourceFilePanel -> getCurrentFile() ));
    if (reader != nullptr)
    {
        StringPairArray metaDataValues = StringPairArray (reader -> metadataValues);
        
        return metaDataValues;
    }
    else
    {
        return Defines::emptyMetaDataFields;
    }
    
    // Check memory leaks here.

}

const void MainComponent::copyFromSourceToDestination()
{
    for (int i = 0; i < sourceFilePanel ->getFileBrowser() ->getNumSelectedFiles(); i++) {
        File fileToCopy = sourceFilePanel -> getCurrentFile(i);
        
        File destinationFile = File (destinationPanel ->getFullPath() + "/" + fileToCopy.getFileName());
        
        bool hasBeenCopied = fileToCopy.copyFileTo(destinationFile);
        if (hasBeenCopied)
        {
            Logger::writeToLog("Worked! for " + fileToCopy.getFileName() + "\n");
        }
        else
        {
            Logger::writeToLog("Didn't work for" + fileToCopy.getFileName() + "\n");
        }
        destinationPanel -> refreshFileBrowser();
    }
    
}

const void MainComponent::moveFromSourceToDestination()
{
    for (int i = 0; i < sourceFilePanel ->getFileBrowser() ->getNumSelectedFiles(); i++) {
        File fileToCopy = sourceFilePanel -> getCurrentFile(i);
        
        File destinationFile = File (destinationPanel ->getFullPath() + "/" + fileToCopy.getFileName());
        
        bool hasBeenCopied = fileToCopy.moveFileTo(destinationFile);
        if (hasBeenCopied)
        {
            Logger::writeToLog("Worked! for " + fileToCopy.getFileName() + "\n");
        }
        else
        {
            Logger::writeToLog("Didn't work for" + fileToCopy.getFileName() + "\n");
        }
        sourceFilePanel -> refreshFileBrowser();
        destinationPanel -> refreshFileBrowser();
    }
    
}


ValueTree MainComponent::loadValueTree (const File& file, bool asXml)
{
    File saveFile = File (Defines::saveDataFilename);
    
    if (saveFile.exists())
    {

        if (asXml)
        {
            if (auto xml = std::unique_ptr<juce::XmlElement> (juce::XmlDocument::parse (file)))
                return juce::ValueTree::fromXml (*xml);
        }
        else
        {
            juce::FileInputStream is (file);
            
            if (is.openedOk())
                return juce::ValueTree::readFromStream (is);
        }
        
        return {};
        
    }
}

bool MainComponent::saveValueTree (const juce::ValueTree& v, const juce::File& file, bool asXml)
{
    const juce::TemporaryFile temp (file);
    
    {
        juce::FileOutputStream os (temp.getFile());
        
        if (! os.getStatus().wasOk())
            return false;
        
        if (asXml)
        {
            if (auto xml = std::unique_ptr<juce::XmlElement> (v.createXml()))
                xml->writeTo (os);
        }
        else
        {
            v.writeToStream (os);
        }
    }
    
    if (temp.getFile().existsAsFile())
        return temp.overwriteTargetFileWithTemporary();
    
    return false;
}


File MainComponent::getSaveFile()
{
    return File ("~/Documents/MetamakerSaves/saveState.xml");
}


ValueTree MainComponent::loadOrCreateDefaultEdit()
{
    ValueTree v (loadValueTree (getSaveFile(), true));
    
    if (! v.isValid())
        //v =  Helpers::createDefaultEdit();
    
    return v;
}



void MainComponent::createSaveDataIfNecessary() {
    File initialDirectory = File (Defines::saveDataDirectoryPath);
    
    if (initialDirectory.exists() == false)
    {
        Result rDirectory = initialDirectory.createDirectory();
        
        if (rDirectory.wasOk())
        {
            saveValueTree(startupPathNode, getSaveFile(), true);
        }
    }
}
