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
    
    inline TextButton* getCopyButton ()             const    noexcept    { return this -> copyButton.get();             }
    inline TextButton* getMoveButton ()             const    noexcept    { return this -> moveButton.get();             }
    inline TextButton* getWriteAndCopyButton ()     const    noexcept    { return this -> writeAndCoppyButton.get();    }
    inline TextButton* getreplaceMetadataButton ()  const    noexcept    { return this -> replaceMetadataButton.get();  }
    
    inline TextButton* getOpenSettingsButton ()     const    noexcept    { return this -> openSettingsButton.get();     }
    
    inline TextButton* getTransportPlayButton ()    const    noexcept    {  return this -> transportPlayButton.get();   }
    inline TextButton* getTransportStopButton ()    const    noexcept    {  return this -> transportStopButton.get();   }
    
    inline TextButton* getTimerStartButton ()       const    noexcept    {  return this -> timerStartButton.get();      }
    inline TextButton* getTimerStopButton ()        const    noexcept    {  return this -> timerStopButton.get();        }

private:
    
    std::unique_ptr<TextButton> copyButton;
    std::unique_ptr<TextButton> moveButton;
    std::unique_ptr<TextButton> writeAndCoppyButton;
    std::unique_ptr<TextButton> replaceMetadataButton;
    
    std::unique_ptr<TextButton> openSettingsButton;
    
    std::unique_ptr<TextButton> transportPlayButton;
    std::unique_ptr<TextButton> transportStopButton;
    
    std::unique_ptr<TextButton> timerStartButton;
    std::unique_ptr<TextButton> timerStopButton;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ButtonPanel)
};
