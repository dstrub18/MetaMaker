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
    
    setSize (800, GUIDefines::universalHeight);
    
    // Make sure that formatManager can read all basic audio file types.
    formatManager.registerBasicFormats();
    
    // Make the WavAudioFormat
    wavAudioFormat = std::make_unique<WavAudioFormat>();
    
    
    // SourceFilePanel Creation
    String initialSourceDirectoryPath = "~/Desktop/metamakerWavs/Source";
    String initialDestinationDirectoryPath = "~/Desktop/metamakerWavs/Destination";
    
    sourceFilePanel  = std::make_unique<FileBrowserPanel> (GUIDefines::initialFileBrowserWidth,
                                                           GUIDefines::universalHeight,
                                                           initialSourceDirectoryPath);
    sourceFilePanel -> setTopLeftPosition(0, GUIDefines::mainWindowTopYCoordinate);
    
    // FileProperty Creation
    propertyPanel = std::make_unique<FileInfoPanel>(GUIDefines::initialFileInfoWidth,
                                                   GUIDefines::universalHeight);
    propertyPanel -> setTopLeftPosition( GUIDefines::initialFileBrowserWidth, GUIDefines::mainWindowTopYCoordinate);
    
    // FileInfoPanel creation
    destinationPanel = std::make_unique<FileBrowserPanel>(GUIDefines::initialFileBrowserWidth,
                                                          GUIDefines::universalHeight,
                                                          initialDestinationDirectoryPath);
    destinationPanel -> setTopLeftPosition(GUIDefines::initialFileBrowserWidth + GUIDefines::initialFileInfoWidth,
                                           GUIDefines::mainWindowTopYCoordinate);
    
    buttonPanel = std::make_unique<ButtonPanel>(GUIDefines::initialButtonPanelWidth, GUIDefines::initialButtonPanelHeight);
    
    buttonPanel -> setTopLeftPosition(GUIDefines::initialFileBrowserWidth, GUIDefines::universalHeight - GUIDefines::initialButtonPanelHeight);
    
    // Set initial Directories
    sourceFilePanel -> setRoot(initialSourceDirectoryPath);
    destinationPanel -> setRoot(initialDestinationDirectoryPath);
    
    // AddAndMakeVisibles
    addAndMakeVisible(*sourceFilePanel);
    addAndMakeVisible(*propertyPanel);
    addAndMakeVisible(*destinationPanel);
    addAndMakeVisible(*buttonPanel);
    
    sourceFilePanel -> getFileBrowser() -> refresh();
    destinationPanel -> getFileBrowser() -> refresh();
    
    
    // LISTENERS
    // Add the listening functionality for the button.
    sourceFilePanel -> getFileBrowser() -> addListener(this);
    buttonPanel     -> getCopyButton()  -> addListener(this);
    

    
    
    kp = KeyPress('m');
    
    
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
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    // Your audio-processing code goes here!

    // For more details, see the help for AudioProcessor::getNextAudioBlock()

    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
    bufferToFill.clearActiveBufferRegion();
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    // You can add your drawing code here!

    
    if (kp.isCurrentlyDown()) {
        Logger::writeToLog("m pressed. \n");
        copyFromSourceToDestination();
        
    }
    
    
    
}

void MainComponent::resized()
{
    
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}


// Override methods from ButtonListener
void MainComponent::buttonClicked(Button* button){
    

    if (button->getButtonText()== "Write Metadata") {
        
        std::cout << "WriteButton clicked! \n";
        
        AudioFormatReader* reader = formatManager.createReaderFor ( sourceFilePanel -> getCurrentFile() );
        if (reader != nullptr)
        {
            File file  = sourceFilePanel -> getCurrentFile();
            std::shared_ptr <StringPairArray> metaDataValues = std::make_shared<StringPairArray> (reader -> metadataValues);
           // metaDataValues -> set("bwav description", editingPanel -> getTextFromEditingLabel() );
            wavAudioFormat -> replaceMetadataInFile(file, *metaDataValues);
            delete reader;
            updateFilePropertyPanel();
        }
        
        else{
            std::cout << "Error!" << " \n";
            
        }
    }
    
    if (button -> getButtonText() == "CopyButton") {
        copyFromSourceToDestination();
    }
    
    
}

// Override methods from FileBrowserListener
void MainComponent::selectionChanged ()
{
    //std::cout << "Selection changed \n";
    
    updateFilePropertyPanel();
}

void MainComponent::fileClicked(const File &file, const MouseEvent &e)
{
    std::cout << "File Clicked! \n";
}

void MainComponent::fileDoubleClicked(const File &file)
{
    std::cout << "File double-Clicked! \n";
}

void MainComponent::browserRootChanged(const File &newBrowserRoot)
{
    std::cout << "Browser Root changed! \n";
}


// Custom Methods

// Updates the FileInfoPanel
void MainComponent::updateFilePropertyPanel()
{
    
    StringPairArray metaDataValues = getMetadataFromFile();
    
    if (metaDataValues != Defines::emptyMetaDataFields || ! sourceFilePanel -> isCurrentlySelectedFileDirectory())
    {
        std::cout << "There's data! \n";
        
        propertyPanel -> setDescriptionLabelText         (metaDataValues.getValue (Defines::descriptionKey, ""));
        propertyPanel -> setArtistLabelText              (metaDataValues.getValue (Defines::originatorKey, ""));
        propertyPanel -> setFileCreationDateLabelText    (metaDataValues.getValue (Defines::originationDateKey, ""));
        propertyPanel -> setFileNameLabelText            (sourceFilePanel->getCurrentFileName());
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
    
    AudioFormatReader* reader = formatManager.createReaderFor ( sourceFilePanel -> getCurrentFile() );
    if (reader != nullptr)
    {
        StringPairArray metaDataValues = StringPairArray (reader -> metadataValues);
        std::cout << metaDataValues.getValue("bwav description", "error") << "\n";
        delete reader;
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
    File fileToCopy = sourceFilePanel -> getCurrentFile ();
    
    File destinationFile = File (destinationPanel ->getFullPath() + "/" + fileToCopy.getFileName());
    
    bool hasBeenCopied = fileToCopy.copyFileTo(destinationFile);
    if (hasBeenCopied)
    {
        Logger::writeToLog("Worked!");
    }
    else
    {
        Logger::writeToLog("Didn't work!");
    }
    destinationPanel -> refreshFileBrowser();
}


