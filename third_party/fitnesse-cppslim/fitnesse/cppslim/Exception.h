//
// Copyright (C) 2013 by Konstantin (Kosta) Baumann. All Rights Reserved.
//

#pragma once

#include "Slim.h"

#include <exception>

namespace slim {

    class Exception :
        public std::exception
    {
    public:
        Exception(std::string message = std::string()) SLIM_NOEXCEPT :
            m_message(std::move(message))
        { }
        
        virtual ~Exception() SLIM_NOEXCEPT { }

        template<typename T>
        Exception& operator<<(const T& obj) {
            std::ostringstream out; out.precision(17);
            out << obj;
            m_message += out.str();
            return *this;
        }

        virtual const char* what() const SLIM_NOEXCEPT {
            return m_message.c_str();
        }

    private:
        std::string m_message;
    };

} // namespace slim
