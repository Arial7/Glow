#include "fileutils.h"

#include "log.h"

namespace Glow { namespace utils {

std::string File::read(){
    std::string line;
    std::string content;
    if(stream_.is_open()){
        while(std::getline(stream_, line)){
            content.append(line + "\n");
        }
    }
    else {
        gLogger.log(Loglevel::ERROR, "Unable to read from file: " + path_,
               "File");
    }

    return content;
}

bool File::write(std::string content){
    if(stream_.is_open()){
        stream_.write(content.c_str(), content.size());
        return true;
    }
    else {
        gLogger.log(Loglevel::ERROR, "Unable to write to file: " + path_, 
                "File");
        return false;
    }
} 

}}
