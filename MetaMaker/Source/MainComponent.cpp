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
    
    setSize (800, 600);

    // Make sure that formatManager can read all basic audio file types.
    formatManager.registerBasicFormats();
    
    

    
    // Make the WavAudioFormat
    wavAudioFormat = std::make_unique<WavAudioFormat>();
    
    
    // FileBrowserPanel Creation
    String initialSourceDirectoryPath = "~/Desktop/metamakerWavs/Source";
    String initialDestinationDirectoryPath = "~/Desktop/metamakerWavs/Destination";
    
    sourceFilePanel  = std::make_unique<FileBrowserPanel> (GUIDefines::initialFileBrowserWidth, GUIDefines::universalHeight, initialSourceDirectoryPath);
    sourceFilePanel -> setTopLeftPosition(0, GUIDefines::mainWindowTopYCoordinate);
    
    // EditPanel Creation
    editingPanel = std::make_unique<FileInfoPanel>(GUIDefines::initialEditPanelWidth, GUIDefines::universalHeight);
    editingPanel -> setTopLeftPosition( 150, GUIDefines::mainWindowTopYCoordinate);
    
    // FileInfoPanel creation
    destinationPanel = std::make_unique<FileBrowserPanel>(GUIDefines::initialFileBrowserWidth, GUIDefines::universalHeight, initialDestinationDirectoryPath);
    destinationPanel->setTopLeftPosition(getLocalBounds().getWidth() / 4 * 3, GUIDefines::mainWindowTopYCoordinate);

    
    // AddAndMakeVisibles
    addAndMakeVisible(*sourceFilePanel);
    addAndMakeVisible(*editingPanel);
    addAndMakeVisible(*destinationPanel);
    
    sourceFilePanel -> getFileBrowser() -> refresh();
    destinationPanel -> getFileBrowser() -> refresh();
    // Add Listeners
                        // Add the listening functionality for the button.
    sourceFilePanel -> getFileBrowser() -> addListener(this);
    //editingPanel -> getWriteMetadataButton() -> addListener(this);
    
    // Set initial Directories
    sourceFilePanel -> setRoot(initialSourceDirectoryPath);
    destinationPanel -> setRoot(initialDestinationDirectoryPath);
    
    
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

    
    
    
}

void MainComponent::resized()
{
    
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}


//==================== override methods from ButtonListener

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
            updateFileInfoPanel();
        }
        
        else{
            std::cout << "Error!" << " \n";
            
        }
    }

    
}

//==================== override methods from FileBrowserListener
void MainComponent::selectionChanged ()
{
    //std::cout << "Selection changed \n";
    
    updateFileInfoPanel();
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

void MainComponent::updateFileInfoPanel() {
    
    /*
        Updates the labels in the FileInfoPanel
     */
    
    StringPairArray metaDataValues = getMetadataFromFile();
    
    if (metaDataValues != Defines::emptyMetaDataFields) {
        
        std::cout << "There's data! \n";
        
        editingPanel -> setDescriptionLabelText (metaDataValues.getValue (Defines::descriptionKey, "error"));
        editingPanel -> setArtistLabelText (metaDataValues.getValue( Defines::originatorKey, "error"));
        editingPanel -> setFileCreationDateLabelText(metaDataValues.getValue(Defines::originationDateKey, "error"));
        editingPanel -> setFileNameLabelText(sourceFilePanel->getCurrentFile().getFileName());
        
    }
    else
    {
        std::cout << "No data! \n";
    }
    
}

    StringPairArray MainComponent::getMetadataFromFile() {
    
    /*
     Retrieves the metadata from the file that's currently selected in the fileBrowser.
     */
    
    
    AudioFormatReader* reader = formatManager.createReaderFor ( sourceFilePanel -> getCurrentFile() );
    if (reader != nullptr)
    {
        std::shared_ptr <StringPairArray> metaDataValues = std::make_shared<StringPairArray> (reader -> metadataValues);
        std::cout << metaDataValues->getValue("bwav description", "error") << "\n";
        delete reader;
        return *metaDataValues;
        
    }
        
    else{
        // std::cout << Defines::emptyMetaDataFields.getDescription() << "temp \n";
        return Defines::emptyMetaDataFields;
        
    }
    
    
    
    // Check memory leaks here.

}


