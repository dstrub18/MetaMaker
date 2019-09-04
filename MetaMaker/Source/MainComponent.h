/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "FileInfoPanel.h"
#include "FileBrowserPanel.h"
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
    
    
    
    
    
    
    
private:
    
    
    
    
    //============================ Flexboxes and the necessary information
    
    
    // This handles the reading of the .wav files and the metadata.
    AudioFormatManager formatManager;
    std::unique_ptr<AudioFormatReaderSource> readerSource;
    File currentFile;
    AudioFormatReader* reader;
    StringPairArray metaDataInformation;            // New Metadata to replace the in the Wav file.
    StringPairArray newMetaData;
    std::unique_ptr<WavAudioFormat> wavAudioFormat; // helper object to replace the metadata.
    
    // FileBrowser and accompanying variables;
    int fileChooserFlag;
    std::unique_ptr<FileBrowserPanel> fileBrowserPanel;
    String initialPath = "~";
    
    
    
    // This displays the information of the file.
    std::unique_ptr<FileInfoPanel> fileInfoPanel;
    
    // Button for writing Metadata into a file.
    TextButton writeMetadataButton;
    
    
    void updateFileInfoPanel();                     // Updates the FileInfoPanel
    void getMetaDatafromFile();                     // Retrieves the MetaData from the file in the fileBrowser.
    //==============================================================================
    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
