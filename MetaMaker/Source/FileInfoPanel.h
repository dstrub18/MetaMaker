/*
  ==============================================================================

    FileInfoPanel.h
    Created: 26 Jun 2020 7:02:57pm
    Author:  Strue Audio

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Defines.h"

//==============================================================================
/*
*/
class FileInfoPanel    : public Component
{
public:
    FileInfoPanel(int panelWidth, int panelHeight);
    ~FileInfoPanel() override;

    void paint (Graphics&) override;
    void resized() override;
    
    inline Label* getFileNameLabel ()               {   return this -> fileNameLabel.get ();        }
    inline Label* getArtistLabel ()                 {   return this -> artistLabel.get ();          }
    inline Label* getFileCreationDateLabel ()       {   return this -> fileCreationDateLabel.get ();     }
    inline Label* getDescriptionLabel ()            {   return this -> descriptionLabel.get ();     }
    
    inline void setFileNameLabelText ( const String& text)              { this -> fileNameLabel -> setText (text, Defines::noNotification);         }
    inline void setArtistLabelText ( const String& text)                { this -> artistLabel -> setText (text, Defines::noNotification);           }
    inline void setFileCreationDateLabelText ( const String& text)      { this->fileCreationDateLabel->setText (text, Defines::noNotification);}
    inline void setDescriptionLabelText ( const String& text)           { this->descriptionLabel->setText (text, Defines::noNotification);     }
    
    inline const String getFileNameLabelText ()         {  return this -> fileNameLabel -> getText (Defines::doNotreturnActiveEditorContents );  }
    inline const String getArtistLabelText ()           {    return this -> artistLabel -> getText (Defines::doNotreturnActiveEditorContents );    }
    inline const String getFileCreationDateLabeltext () {   return this -> fileCreationDateLabel -> getText (Defines::doNotreturnActiveEditorContents); }
    inline const String getDescriptionLabelText ()      {    return this -> descriptionLabel -> getText (Defines::doNotreturnActiveEditorContents ); }
    
    
    const void disableLabelEditing ();
    const void enableLabelEditing ();
    

private:
    
    
    std::unique_ptr<Label> fileNameLabel;
    std::unique_ptr<Label> artistLabel;
    std::unique_ptr<Label> fileCreationDateLabel;
    std::unique_ptr<Label> descriptionLabel;
    
    
    std::unique_ptr<Label> fileNameTitle;
    std::unique_ptr<Label> artistTitle;
    std::unique_ptr<Label> fileCreationDateTitle;
    std::unique_ptr<Label> descriptionTitle;
    
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FileInfoPanel)

    
    
};
