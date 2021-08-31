/*
 * MIT License
 * 
 * Copyright (c) 2021 Uriel Rivas
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * https://github.com/Garz4/zoning/blob/master/LICENSE
 */

#ifndef RESPUESTA_H_
#define RESPUESTA_H_

#include "Mensaje.h"
#include "SocketDatagrama.h"

class Respuesta {
 public:
  Respuesta(int pl)
      : socket_local_(new SocketDatagrama(pl)), anterior_peticion_('n') {}

  ~Respuesta() { delete socket_local_; }

  const Mensaje& pide();
  void responde(const char* respuesta);

  const std::string& ip() const noexcept { return ip_; }
  int puerto() const noexcept { return puerto_; }

 private:
  SocketDatagrama* socket_local_;
  Mensaje recibido_;
  Mensaje enviar_;
  std::string ip_;
  int puerto_;
  int anterior_peticion_;
};

#endif
