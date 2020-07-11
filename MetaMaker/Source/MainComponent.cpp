/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "Defines.h"

//==============================================================================
MainComponent::MainComponent()
                            : state (TransportState::Stopped)

#if JUCE_PROJUCER_LIVE_BUILD
#endif
{
    // Make sure you set the size of the component after
    // you add any child components.
    
    fs = deviceManager.getAudioDeviceSetup().sampleRate;
    
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
    propertyPanel -> setTopLeftPosition (GUIDefines::universalWidth - GUIDefines::initialFileInfoWidth, GUIDefines::mainWindowTopYCoordinate);
    
    
    // Debug Button Panel
    buttonPanel = std::make_unique<ButtonPanel> (GUIDefines::initialButtonPanelWidth, GUIDefines::initialButtonPanelHeight);
    
    buttonPanel -> setTopLeftPosition (GUIDefines::universalWidth - GUIDefines::initialButtonPanelWidth, GUIDefines::propertyPanelHeight - GUIDefines::initialButtonPanelHeight);
    
    // Waveform Panel
    waveformPanel  = std::make_unique<WaveformPanel>(512, formatManager, GUIDefines::universalWidth, 200);
    waveformPanel -> setTopLeftPosition(0, GUIDefines::fileBrowserHeight);
    
    // Settings
    settingsWindowPanel = std::make_unique<SettingsWindowPanel>(GUIDefines::settingsWindowWidth, GUIDefines::settingsWindowHeight);
    settingsWindow = std::make_unique<SettingsWindow>(GUIDefines::settingsWindowWidth, GUIDefines::settingsWindowHeight, "Settings", settingsWindowPanel.get());
    
    
#pragma mark Initialize Valuetree and Create Folder Infrastructure
    
    
    topNode = ValueTree(topNode_ID);
    
    File file = File("~/Documents/MetamakerSaves/saveState.xml");
    
    if (file.existsAsFile())
    {
        topNode = loadValueTree(getSaveFile(), true);
    }
    
    else
    {
        createSaveDataIfNecessary();
        createTempFilesDirectory();
    }
    
    
    
//    startupPathNode.setProperty(startupPath_ID, topNode.getProperty(startupPath_ID), nullptr);
//    outputPathNode = loadValueTree(getSaveFile(), true);
    
    
    
    // Log settings label in Value Tree
    settingsWindowPanel -> setSourcePath (topNode.getPropertyAsValue(startupPath_ID, nullptr).toString());
    settingsWindowPanel -> setOutputPath (topNode.getPropertyAsValue(outputPath_ID, nullptr).toString());
    
    
    startupPath_XML.setAttribute (startupPath_ID, startupPathNode.getProperty (startupPath_ID).toString());
    outputPath_XML.setAttribute (outputPath_ID, outputPathNode.getProperty(outputPath_ID).toString());
    
    // Set initial Directories
    sourceFilePanel -> setRoot (File (settingsWindowPanel -> getSourcePath ()));
    
    // Make sure nothing is selected
    sourceFilePanel -> getFileBrowser() -> deselectAllFiles();
    
    // Nothing is selected. Therefore, make labels non-editable
    propertyPanel -> disableLabelEditing();
    
    // AddAndMakeVisibles
    addAndMakeVisible (*sourceFilePanel);
    addAndMakeVisible (*propertyPanel);
    
    addAndMakeVisible (*buttonPanel);
    addAndMakeVisible (*waveformPanel);
    
    // Set Size
    setSize (GUIDefines::universalWidth, GUIDefines::universalHeight);
    
    
    // LISTENERS
        // Add the listening functionality for the button.
    sourceFilePanel     -> getFileBrowser () -> addListener (this);
    
    buttonPanel         -> getReplaceMetadataButton() -> addListener (this);
    buttonPanel         -> getOpenSettingsButton()    -> addListener (this);
    
    buttonPanel         -> getTransportPlayButton()   -> addListener (this);
    buttonPanel         -> getTransportStopButton()   -> addListener (this);
    
    propertyPanel       -> getArtistLabel () -> addListener (this);
    propertyPanel       -> getFileNameLabel () -> addListener (this);
    propertyPanel       -> getDescriptionLabel () -> addListener (this);
    propertyPanel       -> getFileCreationDateLabel () -> addListener (this);
    
    settingsWindowPanel -> getSourcePathLabel () -> addListener (this);
    settingsWindowPanel -> getSourcePathLabel () -> addListener (sourceFilePanel.get());
    
    buttonPanel         -> getTimerStartButton() -> addListener (this);
    buttonPanel         -> getTimerStopButton() -> addListener (this);
    
    buttonPanel         -> getExportButton()    -> addListener (this);
    
    transportSource.addChangeListener (this);
    
    // Initial Refresh for the FilebrowserPanel
    sourceFilePanel     -> getFileBrowser () -> refresh();
    
    
    
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
    
    
    
    topNode.setProperty(startupPath_ID, settingsWindowPanel -> getSourcePath(), nullptr);
    topNode.setProperty(outputPath_ID, settingsWindowPanel -> getOutputPath(), nullptr);
    saveValueTree(topNode, getSaveFile(), true);
    tempFileDirectory.deleteRecursively();
    
    // This shuts down the audio device and clears the audio source.
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
    
    fs = sampleRate;
    
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
    
    transportSource.getNextAudioBlock (bufferToFill);
    
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

    
#pragma mark Replace
    if (button == buttonPanel -> getReplaceMetadataButton())
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
                Logger::writeToLog ("Error");
            }
        }
    }

#pragma mark OpenSettings
    if (button == buttonPanel -> getOpenSettingsButton())
    {
        if (settingsWindow -> getVisibilityState() == false)
        {
            settingsWindow -> setVisible(true);
            
        }
        else
        {
            settingsWindow -> setVisible(false);
            
        }
        
    }

    
#pragma mark StartTimer
    if (button == buttonPanel -> getTimerStartButton ())
    {
        if (! Timer::isTimerRunning())
        {
            startTimer(1000);
        }
        
        Logger::writeToLog("Timer started");
    }
    
#pragma mark StopTimer
    if (button == buttonPanel -> getTimerStopButton ())
    {
        if (Timer::isTimerRunning ())
        {
            stopTimer();
            Logger::writeToLog("Timer stopped");
        }

    }

#pragma mark Play
    if (button == buttonPanel -> getTransportPlayButton ())
    {
        
        
        File file = sourceFilePanel -> getCurrentFile();
        
        if (file.existsAsFile())
        {
            
            reader = formatManager.createReaderFor (file);
            
            if (reader != nullptr)
            {
        
                float rectangleStartPosition = waveformPanel -> getRectangleStartPosition();
                float totalWaveformWidth = waveformPanel -> getWidth();
                float rectangleWidth = waveformPanel -> getRectangleWidth();
                
                if (rectangleWidth > 0)
                {
                    subsectionReader = new AudioSubsectionReader(reader, rectangleStartPosition / totalWaveformWidth * reader ->lengthInSamples, rectangleWidth / totalWaveformWidth * reader ->lengthInSamples, true);
                    
                    std::unique_ptr<AudioFormatReaderSource> partialSource (new AudioFormatReaderSource (subsectionReader, true));
                    transportSource.setSource (partialSource.get(), 0, nullptr, reader->sampleRate);
                    readerSource.reset (partialSource.release());
                }
                
                else
                {
                    std::unique_ptr<AudioFormatReaderSource> newSource (new AudioFormatReaderSource (reader, true));
                    transportSource.setSource (newSource.get(), 0, nullptr, reader->sampleRate);
                    buttonPanel -> getTransportPlayButton() -> setEnabled (true);
                    readerSource.reset (newSource.release());
                }
                
                
                
            }
        }
        
        changeState (TransportState::Starting);
        
    }
    
#pragma mark Stop
    if (button == buttonPanel -> getTransportStopButton ())
    {
        changeState (TransportState::Stopping);
    }
    
#pragma mark Export
    if (button == buttonPanel -> getExportButton ())
    {
        File inputFile = sourceFilePanel -> getCurrentFile();

        if (inputFile.existsAsFile()) // is File not directory?
        {
            reader = formatManager.createReaderFor(inputFile.createInputStream());
            
            if (reader != nullptr) // Read correctly?
            {
                waveformPanel -> exportSelectedFile (outputPathNode.getPropertyAsValue(outputPath_ID, nullptr).toString());
                
                float rectangleStartPosition = waveformPanel -> getRectangleStartPosition();
                float totalWaveformWidth = waveformPanel -> getWidth();
                float rectangleWidth = waveformPanel -> getRectangleWidth();
                
                File outputFile (settingsWindowPanel -> getOutputPath() + "/" + inputFile.getFileName());
                Logger::writeToLog(inputFile.getFileName());
                Logger::writeToLog(outputFile.getFileName());
                Logger::writeToLog(outputFile.getFullPathName());
                std::unique_ptr<AudioFormatWriter> writer;
                writer.reset(wavAudioFormat -> createWriterFor(new FileOutputStream (outputFile), reader -> sampleRate, reader -> numChannels, reader -> bitsPerSample, reader -> metadataValues, 0));
                
                if (writer != nullptr) // Writer created correctly?
                {
                    if (rectangleWidth > 0)
                    {
                        subsectionReader = new AudioSubsectionReader (reader, rectangleStartPosition / totalWaveformWidth * reader ->lengthInSamples, rectangleWidth / totalWaveformWidth * reader ->lengthInSamples, false);
                        writer -> writeFromAudioReader(*subsectionReader, 0, -1);
                        
                    }
                    else
                    {
                        writer -> writeFromAudioReader(*reader, 0, -1);
                    }
                }
                
                /// This can be done better!
                delete subsectionReader;
                delete reader;
                
            }
        }
    }
    
}


// Override methods from FileBrowserListener
void MainComponent::selectionChanged ()
{
    updateFilePropertyPanel();
    File file = sourceFilePanel -> getCurrentFile ();

    if (sourceFilePanel -> getNumSelectedFiles () == 0 || sourceFilePanel -> isCurrentlySelectedFileDirectory())
    {
        propertyPanel -> disableLabelEditing ();
        
    }
    else
    {
        propertyPanel -> enableLabelEditing ();
        waveformPanel -> setCurrentlySelectedFile(file);
        
    }
    
    
    
    if (file.existsAsFile())
    {
        reader = formatManager.createReaderFor (file);
        
        if (reader != nullptr)
        {
            waveformPanel -> thumbnail.clear ();
            waveformPanel -> thumbnail.setSource (new FileInputSource (file));
            delete reader;
        }
    }
    
    if (file.isDirectory()) {
        waveformPanel -> thumbnail.clear();
    }
    
}

void MainComponent::fileClicked(const File &file, const MouseEvent &e)
{
    
    // Case: User deselects File and thus no files are selected. Therefore, disable label editing
    if (e.mods.isCommandDown()) {
        if (sourceFilePanel -> getNumSelectedFiles() == 1) {
            propertyPanel -> disableLabelEditing();
        }
    }
    
    
}

void MainComponent::fileDoubleClicked(const File &file)
{

}

void MainComponent::browserRootChanged(const File &newBrowserRoot)
{
    sourceFilePanel -> getFileBrowser() -> deselectAllFiles();
}

// ChangeListener
void MainComponent::changeListenerCallback (ChangeBroadcaster* source)
{
    if (source == &transportSource)
    {
        if (transportSource.isPlaying())
        {
            changeState (TransportState::Playing);
        }
        else
        {
            changeState (TransportState::Stopped);
            
        }
    }
}

void MainComponent::changeState (TransportState newState)
{
    if (state != newState)
    {
        state = newState;
        
        switch (state)
        {
            case TransportState::Stopped:
                buttonPanel-> getTransportStopButton() -> setEnabled (false);
                buttonPanel-> getTransportPlayButton() -> setEnabled (true);
                transportSource.setPosition (0.0);
                break;
                
            case TransportState::Starting:
                buttonPanel-> getTransportPlayButton() -> setEnabled(false);
                transportSource.start();
                break;
                
            case TransportState::Playing:
                buttonPanel-> getTransportStopButton() -> setEnabled (true);
                break;
                
            case TransportState::Stopping:
                transportSource.stop();
                break;
        }
    }
}



// Timer Callback override
void MainComponent::timerCallback()
{
    Logger::writeToLog("Timmer Running!");
    Logger::writeToLog("Rectangle Size: " + (String) waveformPanel -> getRectangleWidth());
    
}

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
        startupPathNode.setProperty(startupPath_ID, settingsWindowPanel -> getSourcePath(), nullptr);
        Logger::writeToLog(startupPathNode.getProperty(startupPath_ID).toString());
    }
    
    if (labelThatHasChanged == settingsWindowPanel -> getOutputPathLabel())
    {
        Logger::writeToLog("SettingsWindow panel source path Changed!");
        outputPathNode.setProperty(outputPath_ID, settingsWindowPanel -> getOutputPath(), nullptr);
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

ValueTree MainComponent::loadValueTree (const File& file, const bool& asXml)
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
            saveValueTree(topNode, getSaveFile(), true);
        }
    }
}


void MainComponent::createTempFilesDirectory()
{
    tempFileDirectory = File (Defines::tempFileDirectoryPath);
    tempFileDirectory.createDirectory();
}
