/*
  ==============================================================================

    MetadataManager.cpp
    Created: 14 Feb 2020 7:25:01pm
    Author:  Daniel Strübig

  ==============================================================================
*/

#include "MetadataManager.h"

MetadataManager::MetadataManager ()
{
    this -> oldMetadata.set (Defines::originationDateKey, "Date_old");
    this -> oldMetadata.set (Defines::originatorKey, "Originator_old");
    this -> oldMetadata.set (Defines::descriptionKey, "Description_old");
    
    this -> newMetadata.set (Defines::originationDateKey, "Date_new");
    this -> newMetadata.set (Defines::originatorKey, "Originator_new");
    this -> newMetadata.set (Defines::descriptionKey, "Description_new");
}

const void MetadataManager::printMetadata(StringPairArray& array)
{
    Logger::writeToLog (Defines::originationDateKey + "\t\t" + array [Defines::originationDateKey]);
    Logger::writeToLog (Defines::originatorKey + "\t\t\t\t" + array [Defines::originatorKey]);
    Logger::writeToLog (Defines::descriptionKey + "\t\t\t" + array [Defines::descriptionKey]);
}
