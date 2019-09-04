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
#include "Defines.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class FileInfoPanel  : public Component
{
public:
    //==============================================================================
    FileInfoPanel (int panelWidth, int panelHeight);
    ~FileInfoPanel();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.



    inline void setFileNameLabelText ( const String& text)  { this -> fileNameLabel -> setText(text, Defines::noNotification);   };
    inline void setArtistLabelText ( const String& text)    { this -> artistLabel -> setText(text, Defines::noNotification);     };
    inline void setFileCreationDateLabelText ( const String& text)    { this->fileCreationDate->setText(text, Defines::noNotification);     };
    inline void setDescriptionLabelLabelText ( const String& text)    { this->descriptionLabel->setText(text, Defines::noNotification);     };

    inline const String getFileNameLabelText (){  return this -> fileNameLabel -> getText( Defines::doNotreturnActiveEditorContents );   };
    inline const String getArtistLabelText (){    return this -> artistLabel -> getText( Defines::doNotreturnActiveEditorContents );     };
    inline const String getFileCreationDateLabeltext(){   return this -> fileCreationDate -> getText( Defines::doNotreturnActiveEditorContents ); };
    inline const String getDescriptionLabelText(){    return this -> descriptionLabel -> getText( Defines::doNotreturnActiveEditorContents ); };

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.



    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Label> fileNameLabel;
    std::unique_ptr<Label> artistLabel;
    std::unique_ptr<Label> fileCreationDate;
    std::unique_ptr<Label> descriptionLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FileInfoPanel)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

