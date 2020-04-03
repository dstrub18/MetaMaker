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
    
    TextButton* getCopyButton ()                   { return this -> copyButton.get();             }
    TextButton* getMoveButton ()                   { return this -> moveButton.get();             }
    TextButton* getWriteAndCopyButton ()           { return this -> writeAndCoppyButton.get();    }
    TextButton* getreplaceMetadataButton ()        { return this -> replaceMetadataButton.get();  }
    
    TextButton* getOpenSettingsButton ()                 { return this -> openSettingsButton.get();  }

private:
    
    std::unique_ptr<TextButton> copyButton;
    std::unique_ptr<TextButton> moveButton;
    std::unique_ptr<TextButton> writeAndCoppyButton;
    std::unique_ptr<TextButton> replaceMetadataButton;
    
    std::unique_ptr<TextButton> openSettingsButton;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ButtonPanel)
};
