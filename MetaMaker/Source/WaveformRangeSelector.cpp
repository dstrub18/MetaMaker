/*
  ==============================================================================

    WaveformRangeSelector.cpp
    Created: 23 Apr 2020 9:00:29pm
    Author:  Strue Audio

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "WaveformRangeSelector.h"

//==============================================================================
WaveformRangeSelector::WaveformRangeSelector()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}


WaveformRangeSelector::WaveformRangeSelector(const int& width, const int& height)
{
    setRepaintsOnMouseActivity(true);
    setSize(width, height);
    setOpaque(false);
}

WaveformRangeSelector::~WaveformRangeSelector()
{
}


void WaveformRangeSelector::mouseDown  (const MouseEvent &event)
{
    
}

void WaveformRangeSelector::mouseDrag  (const MouseEvent &event)
{
    auto dragC = DragAndDropContainer::findParentDragContainerFor(this);

    if (dragC -> isDragAndDropActive() == false)
    {
        dragC -> startDragging("descr", this);
        Logger::writeToLog("Dragging!");
    }
}

void WaveformRangeSelector::mouseUp    (const MouseEvent &event)
{
    
}
void WaveformRangeSelector::mouseEnter  (const MouseEvent &event)
{
}



void WaveformRangeSelector::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
    g.setColour(Colours::turquoise);
    
    if (this -> isMouseOver())
    {
        g.setColour(Colours::red);
    }
    
    if (this -> isMouseButtonDown())
    {
        g.setColour(Colours::black);
    }
    g.setOpacity(0.4f);
    g.fillRect(getLocalBounds());
}



void WaveformRangeSelector::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
