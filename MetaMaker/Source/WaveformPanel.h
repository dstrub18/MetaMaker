/*
  ==============================================================================

    WaveformPanel.h
    Created: 6 Mar 2020 11:03:45pm
    Author:  Strue Audio

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Defines.h"

//==============================================================================
/*
*/
class WaveformPanel    : public Component,
                         public ChangeListener
{
public:
    WaveformPanel(int sourceSamplesPerThumbnailSample,
                  AudioFormatManager& formatManager,
                  int width, int height)
    :thumbnail (sourceSamplesPerThumbnailSample, formatManager, thumbnailCache)
    {
        // In your constructor, you should add any child components, and
        // initialise any special settings that your component needs.
        thumbnail.addChangeListener(this);
        
        setSize(width, height);
        
    }

    ~WaveformPanel()
    {
    }
    
    AudioThumbnail thumbnail;
    
    
    // ChangeListener override
    void changeListenerCallback (ChangeBroadcaster* source) override
    {
        if (source == &thumbnail) {
        }
    }
    
    
//==================================================================================
    
    void paint (Graphics& g) override
    {
        /* This demo code just fills the component's background and
           draws some placeholder text to get you started.

           You should replace everything in this method with your own
           drawing code..
        */

        if (thumbnail.getNumChannels() != 0) {
            repaint();
            g.setColour(Colours::white);
            g.fillRect (getLocalBounds());
            repaint ();
            g.setColour (Colours::red);
            thumbnail.drawChannels(g, getLocalBounds(), 0.0, thumbnail.getTotalLength(), 1.0f);
        }
        else
        {
            repaint ();
            g.fillAll (Colours::white);   // clear the background
            
            //g.drawRect (getLocalBounds(), 4);   // draw an outline around the component

        }
    }

    void resized() override
    {
        // This method is where you should set the bounds of any child
        // components that your component contains..

    }

private:
    
    AudioThumbnailCache thumbnailCache  {512};
    Rectangle<int> waveFormArea;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveformPanel)
};
