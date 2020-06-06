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
    setSize(width, height);
    setOpaque(false);
}

WaveformRangeSelector::~WaveformRangeSelector()
{
}


void startDragging    (const var & sourceDescription,
                       Component * sourceComponent,
                       Image dragImage = Image(),
                       bool allowDraggingToOtherJuceWindows = false,
                       const Point< int >* imageOffsetFromMouse = nullptr,
                       const MouseInputSource * inputSourceCausingDrag = nullptr
                       )
{
    Logger::writeToLog("Dragging!");
}


void WaveformRangeSelector::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
    g.setColour(Colours::turquoise);
    g.setOpacity(0.4f);
    g.fillRect(getLocalBounds());
}



void WaveformRangeSelector::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
