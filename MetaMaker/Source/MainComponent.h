/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "FileInfoWindow.h"
//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public AudioAppComponent,
                        public Button::Listener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (Graphics& g) override;
    void resized() override;
    //==============================================================================
    void buttonClicked(Button* button) override;
    
    
    Rectangle<int> localBounds;
    
    Array<FlexItem> itemArray;
    
    FlexBox fullBox;
    
    std::unique_ptr<FileBrowserComponent> fileBrowser; // Filebrowser on the left hand side.
    std::unique_ptr<WildcardFileFilter> wildCardFileFilter; // Makes sure that only Wav files are displayed
    
    
    
    // This handles the reading of the .wav files and the metadata.
    AudioFormatManager formatManager;
    std::unique_ptr<AudioFormatReaderSource> readerSource;
    File currentFile;
    AudioFormatReader* reader;
    StringPairArray metaDataInformation;
    
    
    // This displays the information of the file.
    std::unique_ptr<FileInfoWindow> fileInfoWindow;
    
    // Button for writing Metadata into a file.
    TextButton writeMetadataButton;
    
    // New Metadata to replace the in the Wav file.
    StringPairArray newMetaData;
    
    // helper object to replace the metadata.
    std::unique_ptr<WavAudioFormat> wavAudioFormat;
    
private:

    //==============================================================================
    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
