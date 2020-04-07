/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "FileInfoPanel.h"
#include "FileBrowserPanel.h"
#include "ButtonPanel.h"
#include "WaveformPanel.h"
#include "SettingsWindow.h"
#include "SettingsWindowPanel.h"
//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public AudioAppComponent,
                        public Button::Listener,
                        public FileBrowserListener,
                        public Label::Listener,

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
    
private:
    
    // This handles the reading of the .wav files and the metadata.
    AudioFormatManager formatManager;
    std::unique_ptr<AudioFormatReaderSource> readerSource;
    
    StringPairArray newMetaData;
    
    // helper object to replace the metadata.
    std::unique_ptr<WavAudioFormat> wavAudioFormat;
    
    // FileBrowser and accompanying variables;
    int fileChooserFlag;
    
    // Source files folder
    std::unique_ptr<FileBrowserPanel> sourceFilePanel;
    
    // This displays the actual fields of the source file
    std::unique_ptr<FileInfoPanel> propertyPanel;
    
    // Destination folder.
    std::unique_ptr<FileBrowserPanel> destinationPanel;
    
    // Buttons
    std::unique_ptr<ButtonPanel> buttonPanel;
    
    
    // FileVisualiser
    std::unique_ptr<WaveformPanel> waveformPanel;
    
    
    // Mac Menu
    
    // Settings Window
    std::unique_ptr<SettingsWindow> settingsWindow;
    
    SettingsWindowPanel* settingsWindowPanel;
    
    
    String initialSourceDirectoryPath;
    String initialDestinationDirectoryPath;
    
    // array that stores all changes on the central property panel
    StringPairArray metadataInPanel;
    
    double fs;
    
    
    
        // ValueTree
    Identifier storeInitialPath_ID {"Store Initial Path"};
    Identifier storeInitialPath_String_ID {"name"};
    ValueTree storeInitialPathNode {storeInitialPath_ID};
    
    
    
    /*
     =====================
        LISTENER FUNCTIONS
     =====================
     */ 
        // ButtonListener overrides
    void buttonClicked(Button* button) override;
    
        // FileBrowserListener overrides
    void selectionChanged () override;
    void fileClicked (const File &file, const MouseEvent &e) override;
    void fileDoubleClicked (const File &file) override;
    void browserRootChanged (const File & newBrowserRoot) override;
    
        // LabelListener overrides
    void labelTextChanged (Label* labelThatHasChanged) override;
    void editorShown (Label* ,TextEditor &) override;
    void editorHidden (Label *,TextEditor &) override;
    
    
    // File Copy / Move Functionality
    const void copyFromSourceToDestination();
    const void moveFromSourceToDestination();
    
    // Updates the FileInfoPanel
    void updateFilePropertyPanel();
    
    // Retrieves the MetaData from the file in the fileBrowser.
    StringPairArray getMetadataFromFile();
    
    
    //==============================================================================
    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
