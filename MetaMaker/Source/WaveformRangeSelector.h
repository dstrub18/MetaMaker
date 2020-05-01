/*
  ==============================================================================

    WaveformRangeSelector.h
    Created: 23 Apr 2020 9:00:29pm
    Author:  Strue Audio

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class WaveformRangeSelector    : public Component,
                                 public juce::Component::MouseListener
                                 
{
public:
    
    WaveformRangeSelector();
    
    WaveformRangeSelector(const int& width, const int& height);
    
    ~WaveformRangeSelector();

    // MouseListener inherited functions
    void mouseDown  (const MouseEvent &event) override;
    void mouseDrag  (const MouseEvent &event) override;
    void mouseUp    (const MouseEvent &event) override;
    void mouseEnter  (const MouseEvent &event) override;
    
    
    void paint (Graphics&) override;
    void resized() override;

private:

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveformRangeSelector)
};
