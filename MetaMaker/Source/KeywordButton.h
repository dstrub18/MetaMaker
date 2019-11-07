/*
  ==============================================================================

    KeywordButton.h
    Created: 7 Nov 2019 8:47:04pm
    Author:  Strue Audio

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class KeywordButton    : public Component
{
public:
    KeywordButton();
    KeywordButton(const int& width, const int& height,
                  const int& xPos, const int& yPos,
                  const String& text);
    
    
    
    
    
    ~KeywordButton();

    void paint (Graphics&) override;
    void resized() override;

    const void SetButtonText (const String& text) {   this -> button -> setButtonText(text);    }
    const String getButtonText ()                 {   return this -> button -> getButtonText(); }
    
    
    
private:
    
    TextButton* button;
    
    static DialogWindow textEnterWindow;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KeywordButton)
};
