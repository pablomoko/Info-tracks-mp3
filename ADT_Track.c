#include "ADT_Track.h"

string genre[] = {
"Blues","Classic Rock","Country","Dance","Disco","Funk","Grunge","Hip-Hop","Jazz","Metal","New Age",
"Oldies","Other","Pop","R&B","Rap","Reggae","Rock","Techno","Industrial","Alternative","Ska","Death Metal",
"Pranks","Soundtrack","Euro-Techno","Ambient","Trip-Hop","Vocal","Jazz+Funk","Fusion","Trance","Classical",
"Instrumental","Acid","House","Game","Sound Clip","Gospel","Noise","AlternRock","Bass","Soul","Punk",
"Space","Meditative","Instrumental Pop","Instrumental Rock","Ethnic","Gothic","Darkwave","Techno-Industrial","Electronic",
"Pop-Folk","Eurodance","Dream","Southern Rock","Comedy","Cult","Gangsta","Top 40","Christian Rap","Pop/Funk","Jungle","Native American",
"Cabaret","New Wave","Psychadelic","Rave","Showtunes","Trailer","Lo-Fi","Tribal","Acid Punk","Acid Jazz","Polka",
"Retro","Musical","Rock & Roll","Hard Rock","Folk","Folk-Rock","National Folk","Swing","Fast Fusion","Bebob","Latin","Revival",
"Celtic","Bluegrass","Avantgarde","Gothic Rock","Progressive Rock","Psychedelic Rock","Symphonic Rock","Slow Rock","Big Band",
"Chorus","Easy Listening","Acoustic","Humour","Speech","Chanson","Opera","Chamber Music","Sonata","Symphony","Booty Brass","Primus",
"Porn Groove","Satire","Slow Jam","Club","Tango","Samba","Folklore","Ballad","Poweer Ballad","Rhytmic Soul","Freestyle","Duet",
"Punk Rock","Drum Solo","A Capela","Euro-House","Dance"};

status_t ADT_Track_new (ADT_Track_t ** track){

    if(track == NULL){
        return ERROR_NULL_POINTER;
    }

    if (( *track = (ADT_Track_t*) malloc(sizeof(ADT_Track_t))) == NULL){
        return ERROR_NO_MEMORY;
    }

    return OK;
}

status_t ADT_Track_destroy(void **track){

    if (track == NULL){
        return ERROR_NULL_POINTER;
    }

    free(*track);
    *track = NULL;

    return OK;
}

status_t ADT_Track_set_name(ADT_Track_t *track, const string name){

    if (track == NULL){
        return ERROR_NULL_POINTER;
    }

    memcpy(&(track->name),name,MAX_NAME_LEN);
    track->name[MAX_NAME_LEN] = NUL ;

    return OK;

}

status_t ADT_Track_set_artist(ADT_Track_t *track, const string artist){

    if (track == NULL){
        return ERROR_NULL_POINTER;
    }

    memcpy(&(track->artist),artist,MAX_ARTIST_LEN);
    track->artist[MAX_ARTIST_LEN] = NUL ;

    return OK;
}

status_t ADT_Track_genre(ADT_Track_t *track, unsigned char genre){

    if (track == NULL){
        return ERROR_NULL_POINTER;
    }

    track->genre = genre;

    return OK;
}

status_t ADT_Track_set_year(ADT_Track_t *track, unsigned short year){

    if (track == NULL){
        return ERROR_NULL_POINTER;
    }

    track->year = year;

    return OK;
}

int ADT_Track_compare_by_name(const void *track1, const void *track2){

    return strcmp(((ADT_Track_t*)track2)->name, ((ADT_Track_t*)track1)->name);

}
int ADT_Track_compare_by_artist(const void *track1, const void *track2){

    return strcmp(((ADT_Track_t*)track2)->artist, ((ADT_Track_t*)track1)->artist);

}

int ADT_Track_compare_by_genre(const void *track1, const void *track2){

    return ((((ADT_Track_t*)track2)->genre) - (((ADT_Track_t*)track1)->genre));

}

int ADT_Track_compare_by_year(const void *track1, const void *track2){

    return ((((ADT_Track_t*)track1)->year) - (((ADT_Track_t*)track2)->year));

}

status_t ADT_Track_swap(void* *track1, void* *track2){
  
    ADT_Track_t *aux;

    aux = (ADT_Track_t*) *track1;
    *track1 =(ADT_Track_t*) *track2;
    *track2 = aux;

    return OK;
}


status_t ADT_Track_export_as_xml (const ADT_Track_t *track, const void * context, FILE * fo){

    if (track == NULL){
        return ERROR_NULL_POINTER;
    }
        fprintf(fo,"    <track>\n");
        fprintf(fo,"%s%s%s\n","       <name>",track->name,"</name>");
        fprintf(fo,"%s%s%s\n","       <artist>",track->artist,"</artist>");
        fprintf(fo,"%s%s%s\n","       <genre>",genre[track->genre],"</genre>");
        fprintf(fo,"%s%d%s\n","       <year>",track->year,"</year>");
        fprintf(fo,"    </track>\n");
    return OK;

}

status_t ADT_Track_export_as_csv (const ADT_Track_t *track, const void * delim,FILE *fo){


    if (track == NULL || delim == NULL || fo == NULL){
        return ERROR_NULL_POINTER;
    }

    fprintf(fo,"%s%s",track->name,(string) delim);
    fprintf(fo,"%s%s",track->artist,(string) delim);
    fprintf(fo,"%s%s",genre[track->genre],(string) delim);
    fprintf(fo,"%d\n",track->year);

    return OK;

}
