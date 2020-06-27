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
                        public Timer,
                        public DragAndDropContainer

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
    
#pragma mark Audio File Handling
    AudioFormatManager formatManager;
    AudioFormatReader* reader;
    AudioSubsectionReader* subsectionReader;
    
    std::unique_ptr<AudioFormatReaderSource> readerSource;
    
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
    TransportState state;
    void changeState(TransportState newState);
    
    StringPairArray newMetaData;
    
    // helper object to replace the metadata and exporting.
    std::unique_ptr<WavAudioFormat> wavAudioFormat;
    
    // FileBrowser and accompanying variables;
    int fileChooserFlag;
    
    
    // Folder for storing temporary exported files
    File tempFileDirectory;
    
#pragma mark Components
    // Source files folder
    std::unique_ptr<FileBrowserPanel> sourceFilePanel;
    
    // This displays the actual fields of the source file
    std::unique_ptr<FileInfoPanel> propertyPanel;
    
    
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

    const int filePreviewThreadPriority {3};
    TimeSliceThread filePreviewThread {"Audio File Preview"};
    
    
#pragma mark Value Tree
        // ValueTree
    
    
    Identifier topNode_ID {"TopNode"};
    ValueTree topNode;
    XmlElement topNode_XML {topNode_ID};
    
    Identifier startupPath_ID {"Startup_Path"};
    ValueTree startupPathNode {startupPath_ID};
    XmlElement startupPath_XML {startupPath_ID};
    
    Identifier showSettingsOnStart_ID {"ShowSettingsOnStart"};
    ValueTree showSettingsOnStartNode {showSettingsOnStart_ID};
    XmlElement showSettingsOnStart_XML {showSettingsOnStart_ID};
    
    File getSaveFile ();
    ValueTree loadOrCreateDefaultEdit();
    
    
    /*
     =====================
        LISTENER FUNCTIONS
     =====================
     */
    
#pragma mark Listener overrides
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
    void changeListenerCallback (ChangeBroadcaster* source) override;
    
    
    // Updates the FileInfoPanel
    void updateFilePropertyPanel();
    
    // Retrieves the MetaData from the file in the fileBrowser.
    StringPairArray getMetadataFromFile();
    
    
    // Value tree functions from Dave Rowland
    ValueTree loadValueTree (const File& file, bool asXml);
    bool saveValueTree (const juce::ValueTree& v, const juce::File& file, bool asXml);
    
    // Save Data
    void createSaveDataIfNecessary();
    void createTempFilesDirectory();
    
    //==============================================================================
    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)

};
