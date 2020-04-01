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
                         public ChangeListener,
                         public juce::Component::MouseListener,
                         public KeyListener
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
        
        progress = thumbnail.getProportionComplete();
        progressbar = std::make_unique<ProgressBar>(progress);
        progressbar -> setColour(ProgressBar::backgroundColourId, Colours::aquamarine);
        progressbar -> setColour(ProgressBar::foregroundColourId, Colours::green);
        
        progressbar -> setSize(200, 20);
        progressbar -> setTopLeftPosition(0, 5);
       
        addChildComponent(*progressbar);
        progressbar -> setVisible(false);
        
        amplitudeZoomSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
        amplitudeZoomSlider.setTopLeftPosition(GUIDefines::universalWidth - 30, 0);
        amplitudeZoomSlider.setVisible (false);
        amplitudeZoomSlider.setSize(30, 200);
        //amplitudeZoomSlider.setTextBoxStyle (Slider::TextBoxBelow, true, 400, 20);
        amplitudeZoomSlider.setRange(0.1, 2.0);
        amplitudeZoomSlider.setValue(1.0);
        
        amplitudeZoomSlider.setDoubleClickReturnValue(true, 1.0, ModifierKeys::noModifiers);
        
        
        addAndMakeVisible (&amplitudeZoomSlider);
        amplitudeZoomSlider.setVisible(false);
        
        selectorRect.setSize(0, getHeight());
        selectorRect.setPosition(0, 0);
        
        setWantsKeyboardFocus(true);
        addKeyListener(this);
        
    }

    ~WaveformPanel()
    {
    }
    
    
    // ChangeListener override
    void changeListenerCallback (ChangeBroadcaster* source) override
    {
        if (source == &thumbnail) {
            isRectangleActive = false;
            selectorRect.setWidth (0);
            selectorRect.setPosition (0,0);
            repaint();
        }
    }
    
    AudioThumbnailCache thumbnailCache  {512};
    AudioThumbnail thumbnail;
    
    
    // MouseListener inherited functions
    void mouseDown(const MouseEvent &event) override
    {
        if(event.mods == ModifierKeys::rightButtonModifier && isRectangleActive)
        {
            selectorRect.setWidth (0);
            selectorRect.setPosition (0,0);
            isRectangleActive = false;
            Logger::writeToLog("rectangle not active anymore");
            repaint();
        }
    }
    
    void mouseDrag (const MouseEvent &event) override
    {
        if (event.mods == ModifierKeys::leftButtonModifier)
        {
            isRectangleActive = true;
            Logger::writeToLog("rectangle now active");
            selectorRect.setPosition (event.getMouseDownPosition().getX(), 0);
            
            if (event.getMouseDownPosition ().getX () > event.getPosition ().getX ())
            {
                selectorRect.setWidth (- event.getDistanceFromDragStart());
            }
            
            else
            {
                selectorRect.setWidth (event.getDistanceFromDragStart());
            }

            
            repaint();
        }
        
    }
    
    //KeyListener overrides
    bool keyPressed (const KeyPress &key, Component *originatingComponent) override
    {
        if (key.isKeyCode(KeyPress::downKey))
        {
            Logger::writeToLog((String) selectorRect.getPosition().getX());
        }
        return true;
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
            
            progress = thumbnail.getProportionComplete();
            if (progress < 0.9)
                progressbar -> setVisible (true);
            else
                progressbar -> setVisible (false);

            repaint ();
            g.setColour (Colours::white);
            g.fillRect (getLocalBounds());
            repaint ();
            g.setColour (Colours::red);
            thumbnail.drawChannels (g, getLocalBounds(), 0.0, thumbnail.getTotalLength(), amplitudeZoomSlider.getValue());
            amplitudeZoomSlider.setVisible(true);
            
            if (isRectangleActive)
            {
                g.setColour (Colours::turquoise);
                g.setOpacity(0.4);
                g.fillRect(selectorRect);
            }
            
        }
        else
        {
            repaint ();
            g.fillAll (Colours::white);   // clear the background
            amplitudeZoomSlider.setVisible(false);
            g.drawRect (getLocalBounds(), 4);   // draw an outline around the component

        }
    }

    void resized() override
    {
        // This method is where you should set the bounds of any child
        // components that your component contains..

    }

private:
    double progress;
    std::unique_ptr<ProgressBar> progressbar;
    
    Slider amplitudeZoomSlider;
    
    Rectangle<int> waveFormArea;
    
    // Waveform Slice Selector
    bool isSelectorRectActive;
    
    Rectangle<int> selectorRect;
    Point<int> selectorStartPoint;
    bool isRectangleActive {false};
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveformPanel)
};
