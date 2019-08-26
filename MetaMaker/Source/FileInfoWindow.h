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
class FileInfoWindow  : public Component
{
public:
    //==============================================================================
    FileInfoWindow ();
    ~FileInfoWindow();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    
    std::unique_ptr<Label> fileNameLabel;
    std::unique_ptr<Label> bwavOriginatorLabel;
    std::unique_ptr<Label> fileCreationDateLabel;
    std::unique_ptr<Label> descriptionLabel;
    std::unique_ptr<Label> debugLabel;
    
    
    inline void setFileNameLabel (juce::String text)            { fileNameLabel->setText(text, juce::NotificationType::dontSendNotification); }
    inline void setBwavOriginatorLabel (juce::String text)      { bwavOriginatorLabel->setText(text, juce::NotificationType::dontSendNotification); }
    inline void setFileCreationDateLabel (juce::String text)    { fileCreationDateLabel->setText(text, juce::NotificationType::dontSendNotification); }
    inline void setdescriptionLabel (juce::String text)         { descriptionLabel->setText(text, juce::NotificationType::dontSendNotification); }
    inline void setDebugLabel (juce::String text)            { debugLabel->setText(text, juce::NotificationType::dontSendNotification); }
    
private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
  


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FileInfoWindow)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

