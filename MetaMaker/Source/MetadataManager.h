/*
  ==============================================================================

    MetadataManager.h
    Created: 14 Feb 2020 7:25:01pm
    Author:  Daniel Strübig

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Defines.h"

class MetadataManager
{
    public:
        MetadataManager();
    
        const void setOldMetadata (const StringPairArray& metadata) {  this -> oldMetadata = metadata;    }
        const StringPairArray getOldMetadata ()                     {  return this -> oldMetadata;        }
    
        const void setNewMetadata (const StringPairArray& metadata) {  this -> newMetadata = metadata;    }
        const StringPairArray getNewMetadata ()                     {  return this -> newMetadata;        }
    
        const void printMetadata (StringPairArray& array);
    private:
        StringPairArray oldMetadata;
        StringPairArray newMetadata;
    
};
