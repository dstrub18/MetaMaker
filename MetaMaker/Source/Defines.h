/*
  ==============================================================================

    GUIDefines.h
    Created: 2 Sep 2019 10:55:01am
    Author:  Strue Audio

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

namespace GUIDefines
{
    // Definitions of GUI-related variables that make the code more readable and organized.
    
    static const unsigned int marginBetweenComponents = 10;
    static const unsigned int buttonHeight = 20;
    static const unsigned int buttonWidth = 50;
    
    static const unsigned int initialFileBrowserWidth = 300; // Isn't that handled automatically when using a flexbox?
    static const unsigned int initialFileInfoWidth = 200;
    static const unsigned int initialButtonPanelWidth = initialFileInfoWidth;
    static const unsigned int initialButtonPanelHeight = 100;
    
    static const unsigned int universalHeight = 800;
    static const unsigned int universalWidth = 800;
    
    static const unsigned int fileBrowserHeight = 600;
    static const unsigned int propertyPanelHeight = 600;
    static const unsigned int buttonPanelHeight = 600;
    
    
    static const int mainWindowTopYCoordinate = 0;
    
    static const String metadataButtonText = "Write Metadata";
    
    static const Colour mainWindowBackgroundColour = Colours::grey; //  Unnecessary?
    static const Colour fileBrowserBackgroundColour = Colours::blanchedalmond;
    static const Colour editPanelBackgroundColour = Colours::green;
    static const Colour fileInfoPanelBackgroundColour = Colours::aliceblue;
    
    static const Colour waveFormPanelBackGroundColour = Colours::black;
    static const Colour waveFormPanelWaveFormColour = Colours::darkgreen;

    static const unsigned int labelWidth = 150;
    static const unsigned int labelHeight = 24;
    
    static const unsigned int marginBetweenButtons = 5;
    

    
}

namespace Defines
{
    // Definitions of non-GUI-related variables that make the code more readible and accessible.
    
    
    static const auto noNotification = juce::NotificationType::dontSendNotification;
    
    static const bool doNotreturnActiveEditorContents = false;
    static const bool returnActiveEditorContents = true;
    
    static const StringPairArray emptyMetaDataFields  = StringPairArray ();
 
    // Keys for accessing the metadata
    static const String descriptionKey  = "bwav description";
    static const String originatorKey  = "bwav originator";
    static const String originationDateKey = "bwav origination date";
    
    // Label helpers and dimensions
    static const bool ON_SINGLE_CLICK_EDITABLE = false;
    static const bool ON_DOUBLE_CLICK_EDITABLE = true;
    static const bool DISCARD_CHANGES_ON_LOSS = false;
    
    
}

namespace Utilites
{
    static const void printMetadata(StringPairArray& array)
    {
        Logger::writeToLog (Defines::originationDateKey + "\t\t" + array [Defines::originationDateKey]);
        Logger::writeToLog (Defines::originatorKey + "\t\t\t\t" + array [Defines::originatorKey]);
        Logger::writeToLog (Defines::descriptionKey + "\t\t\t" + array [Defines::descriptionKey]);
    }
}
