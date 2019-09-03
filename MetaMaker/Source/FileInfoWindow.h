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


    inline void setFileNameLabel (const String& text)     { this->fileNameLabel->setText(text, juce::NotificationType::dontSendNotification); };
    inline void setartistLabel (const String& text)          { this->artistLabel->setText(text, juce::NotificationType::dontSendNotification); };
    inline void setBwavOriginatorLabel (const String& text){ this->bwavOriginatorLabel->setText(text, juce::NotificationType::dontSendNotification); };
    inline void setFileCreationDateLabel (const String& text)  { this->fileCreationDate->setText(text, juce::NotificationType::dontSendNotification); };
    inline void setDescriptionLabel(const String& text)   { this->descriptionLabel->setText(text, juce::NotificationType::dontSendNotification); };

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Label> fileNameLabel;
    std::unique_ptr<Label> artistLabel;
    std::unique_ptr<Label> bwavOriginatorLabel;
    std::unique_ptr<Label> fileCreationDate;
    std::unique_ptr<Label> descriptionLabel;
    
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FileInfoWindow)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

