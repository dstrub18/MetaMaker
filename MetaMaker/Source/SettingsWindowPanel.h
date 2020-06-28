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
    inline const String getSourcePath() const                                   {  return this -> sourcePathLabel -> getText ();    }
    inline void setSourcePath (const String& newText)                           {  this -> sourcePathLabel -> setText(newText, Defines::noNotification);   }
    inline void setOutputPath (const String& newText)                           {  this -> outputPathLabel -> setText(newText, Defines::noNotification);   }
    
    inline const void addLabelListener (FileBrowserPanel* newLabelListener)     {    this -> sourcePathLabel -> addListener (newLabelListener); }
    
    inline Label* getSourcePathLabel () const                                   {    return this -> sourcePathLabel.get ();   }
    inline Label* getOutputPathLabel () const                                   {    return this -> outputPathLabel.get ();   }
    
    inline bool getShowOnStartflag () const                                     {   return this -> showOnStartToggle -> getToggleState ();   }
    
    inline String getOutputPath () const                                   {   return this -> outputPathLabel -> getText (); }
    
    // Graphics
    void paint (Graphics&) override;
    void resized() override;

private:
    
    std::unique_ptr<Label> sourcePathLabel;
    std::unique_ptr<TextButton> chooseSourcePathButton;
    std::unique_ptr<ToggleButton> showOnStartToggle;
    
    std::unique_ptr<Label> outputPathLabel;
    std::unique_ptr<TextButton> chooseOutputPathButton;

    
    //JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SettingsWindowPanel)
};
