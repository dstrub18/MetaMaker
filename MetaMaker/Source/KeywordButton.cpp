/*
  ==============================================================================

    KeywordButton.cpp
    Created: 7 Nov 2019 8:47:04pm
    Author:  Strue Audio

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "KeywordButton.h"

//==============================================================================
KeywordButton::KeywordButton(const int& width, const int& height,
                             const int& xPos, const int& yPos,
                             const String& text)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    button = new TextButton(text);
    
    
    button -> setCentrePosition(0, 0);
    button -> changeWidthToFitText(height);
    button -> setColour(TextButton::buttonColourId, Colours::aquamarine);
    
    this -> setSize(button -> getWidth(), button -> getHeight());
    this -> setCentrePosition(xPos, yPos);
    
    
    addAndMakeVisible(button);
    
    //Listeners
    this -> button -> addListener(this);
    
}

KeywordButton::~KeywordButton()
{
    delete button; // This can be done a bit more elegantly!!
}

// ButtonClicked method

void KeywordButton::buttonClicked(Button* button)
    {
        
        this -> textEnterWindow.showDialog("Hello!", this -> button, this -> button, Colours::yellow, true);
        
    }


void KeywordButton::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::white);
    g.setFont (14.0f);
    g.drawText ("KeywordButton", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void KeywordButton::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
