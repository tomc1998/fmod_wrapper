#pragma once

class event;

class event_instance {
  event* type;

  void start();
  void stop();
};
