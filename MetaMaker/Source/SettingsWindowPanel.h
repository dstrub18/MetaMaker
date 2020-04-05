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

//==============================================================================
/*
*/
class SettingsWindowPanel    : public Component
{
public:
    SettingsWindowPanel(int width, int height);
    ~SettingsWindowPanel();

    void paint (Graphics&) override;
    void resized() override;

private:
    
    std::unique_ptr<Label> sourcePathLabel;
    std::unique_ptr<TextButton> chooseFileButton;
    std::unique_ptr<ToggleButton> showOnStartToggle;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SettingsWindowPanel)
};
