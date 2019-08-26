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
    
    File initialFile = File("~");

    // Specifications for files, that should only be displayed.
    const   juce::String fileFilterFilePatterns = "*.wav; *.aiff";
    const   juce::String fileFilterDirPatterns = "*";
    const   juce::String fileFilterDescription = "File Filter";
    wildCardFileFilter = std::make_unique<WildcardFileFilter>(fileFilterFilePatterns,fileFilterDirPatterns,fileFilterDescription);
    
    // Handles the file restrictions and permissions of the File Browser
    int fileChooserFlag =   FileBrowserComponent::FileChooserFlags::openMode +
                            FileBrowserComponent::FileChooserFlags::canSelectFiles +
                            FileBrowserComponent::FileChooserFlags::canSelectMultipleItems;
    
    // Make the File Browser
    fileBrowser = std::make_unique<FileBrowserComponent> (fileChooserFlag, initialFile, wildCardFileFilter, nullptr);
    const juce::String fileBoxName = "";
    fileBrowser->setFilenameBoxLabel(fileBoxName);
    
    // Make the FileInfoWindow
    fileInfoWindow = std::make_unique<FileInfoWindow>();
    fileInfoWindow->setdescriptionLabel("Hello JUCE");
    
    
    // Make the WavAudioFormat
    wavAudioFormat = std::make_unique<WavAudioFormat>();
    
    // Set the writeMetadataButton text.
    writeMetadataButton.setButtonText("Write Metadata");
    
    // Customize thw flex box
    fullBox.flexWrap = FlexBox::Wrap::wrap;
    fullBox.justifyContent = FlexBox::JustifyContent::flexStart;
    fullBox.alignContent = FlexBox::AlignContent::flexStart;
    
    // Add the FileBrowser to the Canvas
    itemArray.add(FlexItem(600,400, *fileBrowser));
    
    // Add the FileInfoWindow to the Canvas
    itemArray.add(FlexItem(300,200,*fileInfoWindow));
    
    // Add the writeMetadataButton.
    itemArray.add(FlexItem(400,300,writeMetadataButton));
    
    fullBox.items = itemArray;

    
    addAndMakeVisible(*fileBrowser);
    addAndMakeVisible(*fileInfoWindow);
    addAndMakeVisible(writeMetadataButton);
    
    // Add the listening functionality for the button.
    writeMetadataButton.addListener(this);
    
    // Set the new metadata. This will be explicit for debugging capabilities for now.
    
    newMetaData = StringPairArray();
    newMetaData.set("bwav Description", "New metadata!");
    
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
    
    currentFile = fileBrowser->getHighlightedFile();
    
    reader = formatManager.createReaderFor(currentFile);
    
    if (reader != nullptr) {
        
        metaDataInformation = reader->metadataValues;
        
        fileInfoWindow-> setdescriptionLabel(metaDataInformation.getValue("bwav description", "error"));
        fileInfoWindow-> setFileNameLabel(   currentFile.getFileName());
        fileInfoWindow-> setFileCreationDateLabel(   metaDataInformation.getValue("bwav time reference", "error"));
        fileInfoWindow-> setBwavOriginatorLabel( metaDataInformation.getValue("bwav originator", "error"));
        
    }
}

void MainComponent::resized()
{
    localBounds = getLocalBounds();
    
    fullBox.performLayout (localBounds);
    
    
    
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}


//==================== override methods from ButtonListener

void MainComponent::buttonClicked(Button* button){

    if (button == &writeMetadataButton) {
        
        currentFile = fileBrowser->getHighlightedFile();
        
        reader = formatManager.createReaderFor(currentFile);
        
        wavAudioFormat->replaceMetadataInFile(currentFile, newMetaData);
        
        
    }
    
}


