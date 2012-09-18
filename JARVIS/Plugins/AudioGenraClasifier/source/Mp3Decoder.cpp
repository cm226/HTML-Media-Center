/*
 * Mp3Decoder.cpp
 *
 *  Created on: Sep 6, 2012
 *      Author: craig
 */

#include "../headers/Mp3Decoder.h"




using namespace std;

Mp3Decoder::Mp3Decoder(string filename)
{
	videoStream=-1;
	audioStream=-1;
}

Mp3Decoder::~Mp3Decoder() {

}


int Mp3Decoder::openMP3(string filename)
{

	  // Register all formats and codecs
	  av_register_all();

	  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)) {
	      fprintf(stderr, "Could not initialize SDL - %s\n", SDL_GetError());
	      exit(1);
	    }

	    // Open video file
	    if(avformat_open_input(&pFormatCtx, filename.c_str(), NULL, NULL)!=0)
	      return -1; // Couldn't open file

	    // Retrieve stream information
	    if(avformat_find_stream_info(pFormatCtx,NULL)<0)
	      return -1; // Couldn't find stream information

	    // Dump information about file onto standard error
	    av_dump_format(pFormatCtx, 0, filename.c_str(), 0);


		for(i=0; i < pFormatCtx->nb_streams; i++) {
		  if(pFormatCtx->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO
		     &&
		       videoStream < 0) {
		    videoStream=i;
		  }
		  if(pFormatCtx->streams[i]->codec->codec_type==AVMEDIA_TYPE_AUDIO && audioStream < 0) {
		    audioStream=i;
		  }
		}
		if(videoStream==-1)
		  return -1; // Didn't find a video stream
		if(audioStream==-1)
		  return -1;

		aCodecCtx=pFormatCtx->streams[audioStream]->codec;
		// Set audio settings from codec info
		wanted_spec.freq = aCodecCtx->sample_rate;
		wanted_spec.format = AUDIO_S16SYS;
		wanted_spec.channels = aCodecCtx->channels;
		wanted_spec.silence = 0;
		wanted_spec.samples = SDL_AUDIO_BUFFER_SIZE;
		//wanted_spec.callback = audio_callback;
		wanted_spec.userdata = aCodecCtx;

		if(SDL_OpenAudio(&wanted_spec, &spec) < 0) {
		    fprintf(stderr, "SDL_OpenAudio: %s\n", SDL_GetError());
		    return -1;
		  }
		  aCodec = avcodec_find_decoder(aCodecCtx->codec_id);
		  if(!aCodec) {
		    fprintf(stderr, "Unsupported codec!\n");
		    return -1;
		  }
		  avcodec_open2(aCodecCtx, aCodec,NULL);

		  // audio_st = pFormatCtx->streams[index]
		  //packet_queue_init(&audioq);
		  SDL_PauseAudio(0);

		  // Get a pointer to the codec context for the video stream
		  pCodecCtx=pFormatCtx->streams[videoStream]->codec;

		  // Find the decoder for the video stream
		  pCodec=avcodec_find_decoder(pCodecCtx->codec_id);
		  if(pCodec==NULL) {
		    fprintf(stderr, "Unsupported codec!\n");
		    return -1; // Codec not found
		  }
		  // Open codec
		  if(avcodec_open2(pCodecCtx, pCodec,NULL)<0)
		    return -1; // Could not open codec

		  return 1;


}


int Mp3Decoder::frameSize()
{

}

void Mp3Decoder::getAudioFrame(uint8_t* data)
{


}
