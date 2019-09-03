/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

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
    
    metaDataInformation = StringPairArray();
    
    File initialDirectory = File("~");
    
    // Make the FileInfoWindow
    // Make the WavAudioFormat
    wavAudioFormat = std::make_unique<WavAudioFormat>();
    
    // Set the writeMetadataButton text.
    writeMetadataButton.setButtonText("Write Metadata");
     
    
    fileBrowserPanel  = std::make_unique<FileBrowserPanel> (getLocalBounds().getWidth()/4, getLocalBounds().getHeight(), initialPath);
    
    // Customize the full flex box
    fullBoxRect = getLocalBounds();
    fullBox.flexWrap = FlexBox::Wrap::noWrap;
    fullBox.justifyContent = FlexBox::JustifyContent::flexStart;
    fullBox.alignContent = FlexBox::AlignContent::stretch;
    
    // Customize the filebrowser FlexBox
    fileBrowserBoxRect.setSize(fullBoxRect.getWidth()/4, fullBoxRect.getHeight());
    fileBrowserBoxRect.setPosition(0,0);
    //fileBrowserBoxRect = fullBoxRect.removeFromLeft(fullBoxRect.getWidth()/4);
    
    // Add the FileBrowser to the FlexBox
    //fileBrowserBox.items.add(FlexItem(fileBrowserBoxRect.getWidth(), fileBrowserBoxRect.getHeight(), *fileBrowser));
    //fileBrowserBox.performLayout(fileBrowserBoxRect);
    
    // Customize the editing FlexBox
    editingBoxRect.setSize(fullBoxRect.getWidth()/2, fullBoxRect.getHeight());
    editingBoxRect.setPosition(fullBoxRect.getWidth()/4, 0);
  
    
    // Customize the fileInfo Flexbox
    fileInfoBoxRect.setSize(fullBoxRect.getWidth()/4, fullBoxRect.getHeight());

    fileInfoBoxRect.setPosition(fullBoxRect.getWidth()/4 * 3, 0);
    
    
    addAndMakeVisible(*fileBrowserPanel);
    // Add the listening functionality for the button.
    writeMetadataButton.addListener(this);
    
    
    
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
    g.setColour(Colours::blueviolet);
    g.fillRect(fileBrowserBoxRect);
    g.setColour(Colours::orangered);
    g.fillRect(editingBoxRect);
    g.setColour(Colours::yellow);
    g.fillRect(fileInfoBoxRect);
    // You can add your drawing code here!

    
    
    reader = formatManager.createReaderFor(currentFile);
    
    if (reader != nullptr) {
        
        metaDataInformation = reader->metadataValues;
        
        fileInfoWindow-> setDescriptionLabel(metaDataInformation.getValue("bwav description", "error"));
        fileInfoWindow-> setFileNameLabel(   currentFile.getFileName());
        fileInfoWindow-> setFileCreationDateLabel(   metaDataInformation.getValue("bwav time reference", "error"));
        fileInfoWindow-> setBwavOriginatorLabel( metaDataInformation.getValue("bwav originator", "error"));
        
    }
}

void MainComponent::resized()
{
    fullBoxRect = getLocalBounds();
    fileBrowserBoxRect.setSize(fullBoxRect.getWidth()/4, fullBoxRect.getHeight());
    fileBrowserBoxRect.setPosition(0,0);
    
    editingBoxRect.setSize(fullBoxRect.getWidth()/2, fullBoxRect.getHeight());
    editingBoxRect.setPosition(fullBoxRect.getWidth()/4, 0);
    
    fileInfoBoxRect.setSize(fullBoxRect.getWidth()/4, fullBoxRect.getHeight());
    fileInfoBoxRect.setPosition(fullBoxRect.getWidth()/4*3, 0);

    //fileBrowserBox.performLayout(fileBrowserBoxRect);
    //editingBox.performLayout(editingBoxRect);
    //fullBox.performLayout (fullBoxRect);
    
    
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    
}


//==================== override methods from ButtonListener

void MainComponent::buttonClicked(Button* button){

    if (button == &writeMetadataButton) {
        
        
        reader = formatManager.createReaderFor(currentFile);
        
        wavAudioFormat->replaceMetadataInFile(currentFile, newMetaData);
        
        
    }
    
}


