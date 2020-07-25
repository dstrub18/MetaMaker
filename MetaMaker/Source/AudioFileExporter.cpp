/*
  ==============================================================================

    AudioFileExporter.cpp
    Created: 24 Jul 2020 4:21:19pm
    Author:  Daniel Strübig

  ==============================================================================
*/

#include "AudioFileExporter.h"

AudioFileExporter::AudioFileExporter ()
{
    audioFormatManager.registerBasicFormats();
    wavAudioFormat = std::make_unique<WavAudioFormat> ();
    
    reader = nullptr;
    subsectionReader = nullptr;
    
    
}

AudioFileExporter::~AudioFileExporter ()
{
    reader = nullptr;
    subsectionReader = nullptr;
}

void AudioFileExporter::exportFullAudioFile(const String& outputPath)
{
    if (fileToExport.existsAsFile())
    {
        reader = audioFormatManager.createReaderFor(fileToExport);
        
        if (reader != nullptr)
        {
            File outputFile = File (outputPath + "/" + fileToExport.getFileName());
            
            std::unique_ptr<AudioFormatWriter> writer;
            writer.reset(wavAudioFormat -> createWriterFor(new FileOutputStream (outputFile), reader -> sampleRate, reader -> numChannels, reader -> bitsPerSample, reader -> metadataValues, 0));
            
            if (writer != nullptr) // Writer created correctly?
            {
                    writer -> writeFromAudioReader(*reader, 0, -1);
            }
            delete reader;
        /// Sketchy Territory!!!
            
        }
    }
    
}
