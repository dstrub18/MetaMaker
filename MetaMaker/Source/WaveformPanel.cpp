/*
  ==============================================================================

    WaveformPanel.cpp
    Created: 23 Apr 2020 10:30:17pm
    Author:  Strue Audio

  ==============================================================================
*/

#include "WaveformPanel.h"

WaveformPanel::WaveformPanel(int sourceSamplesPerThumbnailSample,
              AudioFormatManager& formatManager,
              int width, int height)
:thumbnail (sourceSamplesPerThumbnailSample, formatManager, thumbnailCache)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    rangeSelector = std::make_unique<WaveformRangeSelector>(100, height);
    
    
    setSize(width, height);
    
    
    
    progress = thumbnail.getProportionComplete();
    progressbar = std::make_unique<ProgressBar>(progress);
    progressbar -> setColour(ProgressBar::backgroundColourId, Colours::aquamarine);
    progressbar -> setColour(ProgressBar::foregroundColourId, Colours::green);
    
    progressbar -> setSize(200, 20);
    progressbar -> setTopLeftPosition(0, 5);
    
    addChildComponent(*progressbar);
    progressbar -> setVisible(false);
    
<<<<<<< HEAD
<<<<<<< HEAD
    
    
    
=======
>>>>>>> parent of 0e8b27b... Detection works but not flawlessly. Work on logic and figure out drag and drop inheritance
=======
>>>>>>> parent of 0e8b27b... Detection works but not flawlessly. Work on logic and figure out drag and drop inheritance
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
    
    rangeSelector -> setSize(0, getHeight());
    rangeSelector -> setTopLeftPosition(0, 0);
    
    
    
    
    addAndMakeVisible(rangeSelector.get());
    
    thumbnail.addChangeListener(this);
    
    }


WaveformPanel::~WaveformPanel()
{
}



void WaveformPanel::changeListenerCallback (ChangeBroadcaster* source)
{
    if (source == &thumbnail)
    {
        isRectangleActive = false;
        rangeSelector -> setSize (0, getHeight());
        rangeSelector -> setTopLeftPosition (0,0);
        repaint();
    }
}


void WaveformPanel::mouseDown(const MouseEvent &event)
{
<<<<<<< HEAD
<<<<<<< HEAD
    /// Left click
    if (event.mods == ModifierKeys::leftButtonModifier)
    {
        /// If size is 0, set top left position to mouse down event position
        if (rangeSelector -> isMouseOver() == false)
        {
            rangeSelector -> setSize (0, getHeight());
            rangeSelector -> setTopLeftPosition (event.getMouseDownX(),0);
            isRectangleActive = false;
            
            repaint();
        }
        
        if (rangeSelector -> isMouseOver() && event.mods == ModifierKeys::leftButtonModifier)
        {
            isRectangleActive = true;
        }
        
    }
    /// Right Click: Reset selector
=======
    
>>>>>>> parent of 0e8b27b... Detection works but not flawlessly. Work on logic and figure out drag and drop inheritance
=======
    
>>>>>>> parent of 0e8b27b... Detection works but not flawlessly. Work on logic and figure out drag and drop inheritance
    if(event.mods == ModifierKeys::rightButtonModifier && isRectangleActive)
    {
        
        rangeSelector -> setSize (0, getHeight());
        rangeSelector -> setTopLeftPosition (0,0);
        isRectangleActive = false;
        
        repaint();
    }
}

void WaveformPanel::mouseDrag (const MouseEvent &event)
{
    repaint();
    
    
    
    if (rangeSelector -> getWidth() != 0) {
        const var sourceDescription = "zingy";
        rangeSelector -> startDragging(sourceDescription, rangeSelector.get());
    }
    
    if (event.mods == ModifierKeys::leftButtonModifier)
    {
<<<<<<< HEAD
<<<<<<< HEAD

  
        
=======
>>>>>>> parent of 0e8b27b... Detection works but not flawlessly. Work on logic and figure out drag and drop inheritance
        
=======
        
>>>>>>> parent of 0e8b27b... Detection works but not flawlessly. Work on logic and figure out drag and drop inheritance
  
        if (event.getMouseDownPosition ().getX () > event.getPosition ().getX ())
        {
            // Case: Cursor is left of event down position
            
            rangeSelector -> setSize (-event.getDistanceFromDragStartX (), getHeight ());
            rangeSelector -> setTopRightPosition (event.getMouseDownPosition().getX(), 0);
        }
        else
        {
            // Case: Cursor is right of event down position
            rangeSelector -> setTopLeftPosition (event.getMouseDownPosition().getX (), 0);
            rangeSelector -> setSize (event.getDistanceFromDragStartX (), getHeight ());
        }
<<<<<<< HEAD
<<<<<<< HEAD
        
        
    }
    
    
=======
=======
>>>>>>> parent of 0e8b27b... Detection works but not flawlessly. Work on logic and figure out drag and drop inheritance
    }
    
>>>>>>> parent of 0e8b27b... Detection works but not flawlessly. Work on logic and figure out drag and drop inheritance
}





void WaveformPanel::mouseUp (const MouseEvent &event)
{
    if (event.mods == ModifierKeys::leftButtonModifier)
    {
        isRectangleActive = true;
            // Case: mouseUp occured left of mouseDown
            if (event.getMouseDownPosition ().getX () > event.getPosition ().getX ())
            {
                // Flip rectangle 
                rangeSelector -> setSize (-event.getDistanceFromDragStartX (), getHeight());
                rangeSelector -> setTopLeftPosition (event.getMouseDownPosition ().getX () + event.getDistanceFromDragStartX(), 0);
            }

    }
}


void WaveformPanel::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
     draws some placeholder text to get you started.
     
     You should replace everything in this method with your own
     drawing code..
     */
<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> parent of 0e8b27b... Detection works but not flawlessly. Work on logic and figure out drag and drop inheritance
=======
>>>>>>> parent of 0e8b27b... Detection works but not flawlessly. Work on logic and figure out drag and drop inheritance
    
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
        amplitudeZoomSlider.setVisible (false);
        g.drawRect (getLocalBounds(), 4);   // draw an outline around the component
        
    }
}

void WaveformPanel::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
    }
