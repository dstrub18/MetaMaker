/*
  ==============================================================================

    SettingsWindowPanel.h
    Created: 4 Apr 2020 8:49:26pm
    Author:  Strue Audio

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Defines.h"
#include "FileBrowserPanel.h"

//==============================================================================
/*
*/
class SettingsWindowPanel    : public Component,
                               public Button::Listener,
                               public ChangeBroadcaster
{
public:
    SettingsWindowPanel() = default;
    SettingsWindowPanel(int width, int height);
    
    SettingsWindowPanel (SettingsWindowPanel&);
    SettingsWindowPanel& operator=(const SettingsWindowPanel&);
   
    SettingsWindowPanel (SettingsWindowPanel&&);
    SettingsWindowPanel& operator=(const SettingsWindowPanel&&);
    
    
    
    ~SettingsWindowPanel();
    
    
    // Button Listener overrides
    void buttonClicked (Button* button) override;
    
    // Getters / Setters
    inline const String getLabelText() const {  return this -> sourcePathLabel -> getText();    }
    inline void setLabeltext (const String& newText) {   this -> sourcePathLabel -> setText(newText, Defines::noNotification);   }
    
    inline const void addLabelListener (FileBrowserPanel* newLabelListener) {    this -> sourcePathLabel -> addListener (newLabelListener); }
    
    inline Label* getSourcePathLabel () const {    return this -> sourcePathLabel.get();   }
    
    // Graphics
    void paint (Graphics&) override;
    void resized() override;

private:
    
    std::unique_ptr<Label> sourcePathLabel;
    std::unique_ptr<TextButton> chooseFileButton;
    std::unique_ptr<ToggleButton> showOnStartToggle;
    
    //JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SettingsWindowPanel)
};
