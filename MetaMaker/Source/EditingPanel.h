/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.4

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class EditingPanel  : public Component,
                      public Label::Listener,
                      public Button::Listener
{
public:
    //==============================================================================
    EditingPanel (int panelWidth, int panelHeight);
    ~EditingPanel();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    String getEditLabelText () {  return this -> editingLabel -> getText(); }
    
    void setEditButtonText (const String& text)   { this -> writeMetadataButton -> setButtonText(text);   }
    
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void labelTextChanged (Label* labelThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Label> editingLabel;
    std::unique_ptr<TextButton> writeMetadataButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EditingPanel)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

