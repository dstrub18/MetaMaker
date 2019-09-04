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
    
    // Set the writeMetadataButton text.
    writeMetadataButton.setButtonText("Write Metadata");
    
    
    // FileBrowserPanel Creation
    File initialDirectory = File("~");
    fileBrowserPanel  = std::make_unique<FileBrowserPanel> (GUIDefines::initialFileBrowserWidth, getLocalBounds().getHeight(), initialPath);
    
    // EditPanel Creation
    
    
    // FileInfoPanel creation
    
    fileInfoPanel = std::make_unique<FileInfoPanel>(GUIDefines::initialFileBrowserWidth, getLocalBounds().getHeight());
    fileInfoPanel->setTopLeftPosition(getLocalBounds().getWidth() / 4 * 3, GUIDefines::mainWindowTopYCoordinate);
    
    
    // AddAndMakeVisibles
    addAndMakeVisible(*fileBrowserPanel);
    addAndMakeVisible(*fileInfoPanel);

    // Add Listeners
    writeMetadataButton.addListener(this); // Add the listening functionality for the button.
    fileBrowserPanel -> getFileBrowser() -> addListener(this);
    
    
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

    // TBC
    
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
    
    std::optional<StringPairArray> metaDataValues = getMetadataFromFile();
    
    if (metaDataValues.has_value()) {
        std::cout << "There's data! \n";
    }
    else
    {
        std::cout << "No data! \n";
    }
    
}

std::optional<StringPairArray> MainComponent::getMetadataFromFile() {
    
    /*
     Retrieves the metadata from the file that's currently selected in the fileBrowser.
     */
    
    reader = formatManager.createReaderFor ( fileBrowserPanel->getCurrentFile() );
    if (reader != nullptr)
    {
      return reader->metadataValues;
      
    }
    
    //Investigate std::optional!!!!
    return {}; // This returns an empty std::optional
    
    
    // Check memory leaks here.
}


