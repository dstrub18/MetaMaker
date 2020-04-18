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
                        public ChangeListener,
                        public Timer

{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();
    
    void timerCallback() override;


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
    std::unique_ptr<AudioSubsectionReader> subsectionReader;
    
    
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
    
    std::unique_ptr<SettingsWindowPanel> settingsWindowPanel;
    
    
    String initialSourceDirectoryPath;
    String initialDestinationDirectoryPath;
    
    // array that stores all changes on the central property panel
    StringPairArray metadataInPanel;
    
    double fs;
    
    enum class TransportState
    {
        Stopped,
        Starting,
        Playing,
        Stopping
    };
    
    int playbackStartPosition {0};
    int playbackTimeSelectionRange {0};
    
    AudioTransportSource transportSource;
    TransportState transportState;
    void changeState (TransportState newState);
    
    const int filePreviewThreadPriority {3};
    TimeSliceThread filePreviewThread {"Audio File Preview"};
    
    
        // ValueTree
    Identifier startupPath_ID {"Startup_Path"};
    ValueTree startupPathNode {startupPath_ID};
    XmlElement startupPath_XML {startupPath_ID};
    File getSaveFile();
    ValueTree loadOrCreateDefaultEdit();
    
    
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
    
        // ChangeListener
    void changeListenerCallback(juce::ChangeBroadcaster *source) override;
    
    
    // File Copy / Move Functionality
    const void copyFromSourceToDestination();
    const void moveFromSourceToDestination();
    
    // Updates the FileInfoPanel
    void updateFilePropertyPanel();
    
    // Retrieves the MetaData from the file in the fileBrowser.
    StringPairArray getMetadataFromFile();
    
    
    // Value tree functions from Dave Rowland
    ValueTree loadValueTree (const File& file, bool asXml);
    bool saveValueTree (const juce::ValueTree& v, const juce::File& file, bool asXml);
    
    // Save Data
    void createSaveDataIfNecessary();
    
    //==============================================================================
    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)

};
