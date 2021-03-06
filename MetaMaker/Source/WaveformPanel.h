/*
  ==============================================================================

    WaveformPanel.h
    Created: 6 Mar 2020 11:03:45pm
    Author:  Strue Audio

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#include "WaveformRangeSelector.h"
#include "Defines.h"

//==============================================================================
/*
*/
class WaveformPanel    : public Component,
                         public ChangeListener,
                         public juce::Component::MouseListener,
                         public DragAndDropContainer
                         
{
public:
    WaveformPanel(int sourceSamplesPerThumbnailSample,
                  AudioFormatManager& formatManager,
                  int width, int height);

    ~WaveformPanel();
    
    
    // ChangeListener override
    void changeListenerCallback (ChangeBroadcaster* source) override;

    
    // MouseListener inherited functions
    void mouseDown  (const MouseEvent &event) override;
    void mouseDrag  (const MouseEvent &event) override;
    void mouseUp    (const MouseEvent &event) override;
    
    
//==================================================================================
    
    void paint (Graphics& g) override;

    void resized() override;
    
    inline int getRectangleWidth ()            const noexcept   {   return this -> rangeSelector -> getWidth (); }
    inline int getRectangleStartPosition ()    const noexcept   {   return this -> rangeSelector -> getX ();     }
    
    inline int getComponentWidth ()            const noexcept   {   return this -> getWidth ();                  }

    void setCurrentlySelectedFile (const File& file) noexcept   {    currentlySelectedFile = file;               }
    
    void exportSelectedFile (const String& outputPath);
    
    
    
    
    AudioThumbnailCache thumbnailCache  {512};
    AudioThumbnail thumbnail;
    
    
    std::unique_ptr<WavAudioFormat> wavAudioFormat;
    AudioFormatManager audioFormatManager;
    AudioFormatReader* reader;
    AudioSubsectionReader* subsectionReader;
    
    
private:
    
    double progress {0.0};
    std::unique_ptr<ProgressBar> progressbar;
    
    Slider amplitudeZoomSlider;
    
    Rectangle<int> waveFormArea;
    
    // Waveform SelectEditor
    bool isRectangleActive {false};
    
    std::unique_ptr<WaveformRangeSelector> rangeSelector;
    
    File currentlySelectedFile;
    File outputFile;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveformPanel)
};
