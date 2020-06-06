/*
  ==============================================================================

    ButtonPanel.h
    Created: 8 Feb 2020 7:36:34pm
    Author:  Strue Audio

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class ButtonPanel    : public Component
{
public:
    ButtonPanel(const int& panelWidth, const int& panelHeight);
    ~ButtonPanel();

    void paint (Graphics&) override;
    void resized() override;
    
    inline TextButton* getReplaceMetadataButton ()  const    noexcept    { return this -> replaceMetadataButton.get();  }
    
    inline TextButton* getOpenSettingsButton ()     const    noexcept    { return this -> openSettingsButton.get();     }
    
    inline TextButton* getTransportPlayButton ()    const    noexcept    {  return this -> transportPlayButton.get();   }
    inline TextButton* getTransportStopButton ()    const    noexcept    {  return this -> transportStopButton.get();   }
    
    inline TextButton* getTimerStartButton ()       const    noexcept    {  return this -> timerStartButton.get();      }
    inline TextButton* getTimerStopButton ()        const    noexcept    {  return this -> timerStopButton.get();       }
    
    inline TextButton* getExportButton ()           const    noexcept    {  return this -> exportButton.get();          }

private:

    
    std::unique_ptr<TextButton> replaceMetadataButton;
    
    std::unique_ptr<TextButton> openSettingsButton;
    
    std::unique_ptr<TextButton> transportPlayButton;
    std::unique_ptr<TextButton> transportStopButton;
    
    std::unique_ptr<TextButton> timerStartButton;
    std::unique_ptr<TextButton> timerStopButton;
    
    std::unique_ptr<TextButton> exportButton;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ButtonPanel)
};
