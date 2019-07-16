/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public AudioAppComponent
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
    
    struct FileBrowser : public Component{ // Deemed unnecessary
        
        Colour m_backgroundColour;
        
        FileBrowserComponent m_fbc;
        TextButton m_backButton;
        void setBackGroundColour(Colour c){
            this->m_backgroundColour = c;
        }
        
        void paint(Graphics &g) override
        {
            g.fillAll(m_backgroundColour);
            
        };
        
        
    };
    
    Rectangle<int> localBounds;
    
    Array<FlexItem> itemArray;
    
    FlexBox fullBox;
    
    std::unique_ptr<FileBrowserComponent> fileBrowser;
    WildcardFileFilter* wildCardFileFilter; // Makes sure that only Wav files are displayed
    
    TextButton openButton;
    
    //==============================================================================
    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
