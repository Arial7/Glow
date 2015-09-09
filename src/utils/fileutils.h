#include <fstream>
#include <iostream>
#include <string>

namespace Glow { namespace utils {

    class File {
        private:
            std::fstream stream_;
            std::string path_;
        public:
            File(std::string path){
                stream_ = std::fstream(path, std::fstream::in |
                    std::fstream::out | std::fstream::app);
                path_ = path;
            };
            File(std::string path, bool overwrite) {
                if(overwrite)
                    stream_ = std::fstream(path, std::fstream::in |
                        std::fstream::out | std::fstream::trunc);
                else
                    stream_ = std::fstream(path, std::fstream::in |
                        std::fstream::out | std::fstream::app);
                path_ = path;
            };

            ~File(){stream_.close();};
            std::string read();
            bool write(std::string content);

    };


}}
