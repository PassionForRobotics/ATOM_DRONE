#include "Logging.h"

#if !defined(STRINGIFY)
#define STRINGIFY(x) #x
#endif

#if !defined(TOSTRING)
#define TOSTRING(x) STRINGIFY(x)
#endif

#define TIMESTR(x,y) Serial.print(y);Serial.print("(");Serial.print(x);Serial.print("): ");

void Logging::Init(int level, long baud){
  _level = constrain(level,LOG_LEVEL_NOOUTPUT,LOG_LEVEL_VERBOSE);
  _baud = baud;
  Serial.begin(_baud);
}

void Logging::Reinit(int level){
  _level = constrain(level,LOG_LEVEL_NOOUTPUT,LOG_LEVEL_VERBOSE);
  this->Info("LOG level reinit %d"CR, level);
}

void Logging::Error(char* msg, ...){
  if (LOG_LEVEL_ERRORS <= _level) {
    print ("ERR: ",0);
    TIMESTR(millis(), micros());
    va_list args;
    va_start(args, msg);
    print(msg,args);
  }
}

void Logging::Warning(char* msg, ...){
  if (LOG_LEVEL_WARNINGS <= _level) {
    print ("WRN: ",0);
    TIMESTR(millis(), micros());
    va_list args;
    va_start(args, msg);
    print(msg,args);
  }
}


void Logging::Info(char* msg, ...){
  if (LOG_LEVEL_INFOS <= _level) {
    print ("INF: ",0);
    TIMESTR(millis(), micros());
    va_list args;
    va_start(args, msg);
    print(msg,args);
  }
}

void Logging::Debug(char* msg, ...){
  if (LOG_LEVEL_DEBUG <= _level) {
    print ("DBG: ",0);
    TIMESTR(millis(), micros());
    va_list args;
    va_start(args, msg);
    print(msg,args);
  }
}


void Logging::Verbose(char* msg, ...){
  if (LOG_LEVEL_VERBOSE <= _level) {
    print ("VRB: ",0);
    TIMESTR(millis(), micros());
    va_list args;
    va_start(args, msg);
    print(msg,args);
  }
}



void Logging::print(const char *format, va_list args) {
  //
  // loop through format string
  for (; *format != 0; ++format) {
    if (*format == '%') {
      ++format;
      if (*format == '\0') break;
      if (*format == '%') {
        Serial.print(*format);
        continue;
      }
      if( *format == 's' ) {
        register char *s = (char *)va_arg( args, int );
        Serial.print(s);
        continue;
      }
      if( *format == 'd' || *format == 'i') {
        Serial.print(va_arg( args, int ),DEC);
        continue;
      }
      if( *format == 'x' ) {
        Serial.print(va_arg( args, int ),HEX);
        continue;
      }
      if( *format == 'X' ) {
        Serial.print("0x");
        Serial.print(va_arg( args, int ),HEX);
        continue;
      }
      if( *format == 'b' ) {
        Serial.print(va_arg( args, int ),BIN);
        continue;
      }
      if( *format == 'B' ) {
        Serial.print("0b");
        Serial.print(va_arg( args, int ),BIN);
        continue;
      }
      if( *format == 'l' ) {
        Serial.print(va_arg( args, long ),DEC);
        continue;
      }

      if( *format == 'c' ) {
        Serial.print((char)(va_arg( args, int )));
        continue;
      }
      if( *format == 't' ) {
        if (va_arg( args, int ) == 1) {
          Serial.print("T");
        }
        else {
          Serial.print("F");
        }
        continue;
      }
      if( *format == 'T' ) {
        if (va_arg( args, int ) == 1) {
          Serial.print("true");
        }
        else {
          Serial.print("false");
        }
        continue;
      }

    }
    Serial.print(*format);
  }
}

Logging Log = Logging();
