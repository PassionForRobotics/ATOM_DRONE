;; Auto-generated. Do not edit!


(when (boundp 'atom_esp_listener::alldata)
  (if (not (find-package "ATOM_ESP_LISTENER"))
    (make-package "ATOM_ESP_LISTENER"))
  (shadow 'alldata (find-package "ATOM_ESP_LISTENER")))
(unless (find-package "ATOM_ESP_LISTENER::ALLDATA")
  (make-package "ATOM_ESP_LISTENER::ALLDATA"))

(in-package "ROS")
;;//! \htmlinclude alldata.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass atom_esp_listener::alldata
  :super ros::object
  :slots (_H _mpuData_AcX _mpuData_AcY _mpuData_AcZ _mpuData_timestamp _mpuData_Tmp _mpuData_GyX _mpuData_GyY _mpuData_GyZ _mpuRAW_AcX _mpuRAW_AcY _mpuRAW_AcZ _mpuRAW_timestamp _mpuRAW_Tmp _mpuRAW_GyX _mpuRAW_GyY _mpuRAW_GyZ _pingheight _ppfb_timestamp _ppfb_Input _ppfb_Kd _ppfb_Ki _ppfb_Kp _ppfb_Output _ppfb_Setpoint _pplr_timestamp _pplr_Input _pplr_Kd _pplr_Ki _pplr_Kp _pplr_Output _pplr_Setpoint _ppud_timestamp _ppud_Input _ppud_Kd _ppud_Ki _ppud_Kp _ppud_Output _ppud_Setpoint _yaw _pitch _roll _timestamp _tune_type ))

(defmethod atom_esp_listener::alldata
  (:init
   (&key
    ((:H __H) (instance std_msgs::Header :init))
    ((:mpuData_AcX __mpuData_AcX) 0)
    ((:mpuData_AcY __mpuData_AcY) 0)
    ((:mpuData_AcZ __mpuData_AcZ) 0)
    ((:mpuData_timestamp __mpuData_timestamp) 0)
    ((:mpuData_Tmp __mpuData_Tmp) 0)
    ((:mpuData_GyX __mpuData_GyX) 0)
    ((:mpuData_GyY __mpuData_GyY) 0)
    ((:mpuData_GyZ __mpuData_GyZ) 0)
    ((:mpuRAW_AcX __mpuRAW_AcX) 0)
    ((:mpuRAW_AcY __mpuRAW_AcY) 0)
    ((:mpuRAW_AcZ __mpuRAW_AcZ) 0)
    ((:mpuRAW_timestamp __mpuRAW_timestamp) 0)
    ((:mpuRAW_Tmp __mpuRAW_Tmp) 0)
    ((:mpuRAW_GyX __mpuRAW_GyX) 0)
    ((:mpuRAW_GyY __mpuRAW_GyY) 0)
    ((:mpuRAW_GyZ __mpuRAW_GyZ) 0)
    ((:pingheight __pingheight) 0)
    ((:ppfb_timestamp __ppfb_timestamp) 0)
    ((:ppfb_Input __ppfb_Input) 0.0)
    ((:ppfb_Kd __ppfb_Kd) 0.0)
    ((:ppfb_Ki __ppfb_Ki) 0.0)
    ((:ppfb_Kp __ppfb_Kp) 0.0)
    ((:ppfb_Output __ppfb_Output) 0.0)
    ((:ppfb_Setpoint __ppfb_Setpoint) 0.0)
    ((:pplr_timestamp __pplr_timestamp) 0)
    ((:pplr_Input __pplr_Input) 0.0)
    ((:pplr_Kd __pplr_Kd) 0.0)
    ((:pplr_Ki __pplr_Ki) 0.0)
    ((:pplr_Kp __pplr_Kp) 0.0)
    ((:pplr_Output __pplr_Output) 0.0)
    ((:pplr_Setpoint __pplr_Setpoint) 0.0)
    ((:ppud_timestamp __ppud_timestamp) 0)
    ((:ppud_Input __ppud_Input) 0.0)
    ((:ppud_Kd __ppud_Kd) 0.0)
    ((:ppud_Ki __ppud_Ki) 0.0)
    ((:ppud_Kp __ppud_Kp) 0.0)
    ((:ppud_Output __ppud_Output) 0.0)
    ((:ppud_Setpoint __ppud_Setpoint) 0.0)
    ((:yaw __yaw) 0.0)
    ((:pitch __pitch) 0.0)
    ((:roll __roll) 0.0)
    ((:timestamp __timestamp) 0)
    ((:tune_type __tune_type) 0)
    )
   (send-super :init)
   (setq _H __H)
   (setq _mpuData_AcX (round __mpuData_AcX))
   (setq _mpuData_AcY (round __mpuData_AcY))
   (setq _mpuData_AcZ (round __mpuData_AcZ))
   (setq _mpuData_timestamp (round __mpuData_timestamp))
   (setq _mpuData_Tmp (round __mpuData_Tmp))
   (setq _mpuData_GyX (round __mpuData_GyX))
   (setq _mpuData_GyY (round __mpuData_GyY))
   (setq _mpuData_GyZ (round __mpuData_GyZ))
   (setq _mpuRAW_AcX (round __mpuRAW_AcX))
   (setq _mpuRAW_AcY (round __mpuRAW_AcY))
   (setq _mpuRAW_AcZ (round __mpuRAW_AcZ))
   (setq _mpuRAW_timestamp (round __mpuRAW_timestamp))
   (setq _mpuRAW_Tmp (round __mpuRAW_Tmp))
   (setq _mpuRAW_GyX (round __mpuRAW_GyX))
   (setq _mpuRAW_GyY (round __mpuRAW_GyY))
   (setq _mpuRAW_GyZ (round __mpuRAW_GyZ))
   (setq _pingheight (round __pingheight))
   (setq _ppfb_timestamp (round __ppfb_timestamp))
   (setq _ppfb_Input (float __ppfb_Input))
   (setq _ppfb_Kd (float __ppfb_Kd))
   (setq _ppfb_Ki (float __ppfb_Ki))
   (setq _ppfb_Kp (float __ppfb_Kp))
   (setq _ppfb_Output (float __ppfb_Output))
   (setq _ppfb_Setpoint (float __ppfb_Setpoint))
   (setq _pplr_timestamp (round __pplr_timestamp))
   (setq _pplr_Input (float __pplr_Input))
   (setq _pplr_Kd (float __pplr_Kd))
   (setq _pplr_Ki (float __pplr_Ki))
   (setq _pplr_Kp (float __pplr_Kp))
   (setq _pplr_Output (float __pplr_Output))
   (setq _pplr_Setpoint (float __pplr_Setpoint))
   (setq _ppud_timestamp (round __ppud_timestamp))
   (setq _ppud_Input (float __ppud_Input))
   (setq _ppud_Kd (float __ppud_Kd))
   (setq _ppud_Ki (float __ppud_Ki))
   (setq _ppud_Kp (float __ppud_Kp))
   (setq _ppud_Output (float __ppud_Output))
   (setq _ppud_Setpoint (float __ppud_Setpoint))
   (setq _yaw (float __yaw))
   (setq _pitch (float __pitch))
   (setq _roll (float __roll))
   (setq _timestamp (round __timestamp))
   (setq _tune_type (round __tune_type))
   self)
  (:H
   (&rest __H)
   (if (keywordp (car __H))
       (send* _H __H)
     (progn
       (if __H (setq _H (car __H)))
       _H)))
  (:mpuData_AcX
   (&optional __mpuData_AcX)
   (if __mpuData_AcX (setq _mpuData_AcX __mpuData_AcX)) _mpuData_AcX)
  (:mpuData_AcY
   (&optional __mpuData_AcY)
   (if __mpuData_AcY (setq _mpuData_AcY __mpuData_AcY)) _mpuData_AcY)
  (:mpuData_AcZ
   (&optional __mpuData_AcZ)
   (if __mpuData_AcZ (setq _mpuData_AcZ __mpuData_AcZ)) _mpuData_AcZ)
  (:mpuData_timestamp
   (&optional __mpuData_timestamp)
   (if __mpuData_timestamp (setq _mpuData_timestamp __mpuData_timestamp)) _mpuData_timestamp)
  (:mpuData_Tmp
   (&optional __mpuData_Tmp)
   (if __mpuData_Tmp (setq _mpuData_Tmp __mpuData_Tmp)) _mpuData_Tmp)
  (:mpuData_GyX
   (&optional __mpuData_GyX)
   (if __mpuData_GyX (setq _mpuData_GyX __mpuData_GyX)) _mpuData_GyX)
  (:mpuData_GyY
   (&optional __mpuData_GyY)
   (if __mpuData_GyY (setq _mpuData_GyY __mpuData_GyY)) _mpuData_GyY)
  (:mpuData_GyZ
   (&optional __mpuData_GyZ)
   (if __mpuData_GyZ (setq _mpuData_GyZ __mpuData_GyZ)) _mpuData_GyZ)
  (:mpuRAW_AcX
   (&optional __mpuRAW_AcX)
   (if __mpuRAW_AcX (setq _mpuRAW_AcX __mpuRAW_AcX)) _mpuRAW_AcX)
  (:mpuRAW_AcY
   (&optional __mpuRAW_AcY)
   (if __mpuRAW_AcY (setq _mpuRAW_AcY __mpuRAW_AcY)) _mpuRAW_AcY)
  (:mpuRAW_AcZ
   (&optional __mpuRAW_AcZ)
   (if __mpuRAW_AcZ (setq _mpuRAW_AcZ __mpuRAW_AcZ)) _mpuRAW_AcZ)
  (:mpuRAW_timestamp
   (&optional __mpuRAW_timestamp)
   (if __mpuRAW_timestamp (setq _mpuRAW_timestamp __mpuRAW_timestamp)) _mpuRAW_timestamp)
  (:mpuRAW_Tmp
   (&optional __mpuRAW_Tmp)
   (if __mpuRAW_Tmp (setq _mpuRAW_Tmp __mpuRAW_Tmp)) _mpuRAW_Tmp)
  (:mpuRAW_GyX
   (&optional __mpuRAW_GyX)
   (if __mpuRAW_GyX (setq _mpuRAW_GyX __mpuRAW_GyX)) _mpuRAW_GyX)
  (:mpuRAW_GyY
   (&optional __mpuRAW_GyY)
   (if __mpuRAW_GyY (setq _mpuRAW_GyY __mpuRAW_GyY)) _mpuRAW_GyY)
  (:mpuRAW_GyZ
   (&optional __mpuRAW_GyZ)
   (if __mpuRAW_GyZ (setq _mpuRAW_GyZ __mpuRAW_GyZ)) _mpuRAW_GyZ)
  (:pingheight
   (&optional __pingheight)
   (if __pingheight (setq _pingheight __pingheight)) _pingheight)
  (:ppfb_timestamp
   (&optional __ppfb_timestamp)
   (if __ppfb_timestamp (setq _ppfb_timestamp __ppfb_timestamp)) _ppfb_timestamp)
  (:ppfb_Input
   (&optional __ppfb_Input)
   (if __ppfb_Input (setq _ppfb_Input __ppfb_Input)) _ppfb_Input)
  (:ppfb_Kd
   (&optional __ppfb_Kd)
   (if __ppfb_Kd (setq _ppfb_Kd __ppfb_Kd)) _ppfb_Kd)
  (:ppfb_Ki
   (&optional __ppfb_Ki)
   (if __ppfb_Ki (setq _ppfb_Ki __ppfb_Ki)) _ppfb_Ki)
  (:ppfb_Kp
   (&optional __ppfb_Kp)
   (if __ppfb_Kp (setq _ppfb_Kp __ppfb_Kp)) _ppfb_Kp)
  (:ppfb_Output
   (&optional __ppfb_Output)
   (if __ppfb_Output (setq _ppfb_Output __ppfb_Output)) _ppfb_Output)
  (:ppfb_Setpoint
   (&optional __ppfb_Setpoint)
   (if __ppfb_Setpoint (setq _ppfb_Setpoint __ppfb_Setpoint)) _ppfb_Setpoint)
  (:pplr_timestamp
   (&optional __pplr_timestamp)
   (if __pplr_timestamp (setq _pplr_timestamp __pplr_timestamp)) _pplr_timestamp)
  (:pplr_Input
   (&optional __pplr_Input)
   (if __pplr_Input (setq _pplr_Input __pplr_Input)) _pplr_Input)
  (:pplr_Kd
   (&optional __pplr_Kd)
   (if __pplr_Kd (setq _pplr_Kd __pplr_Kd)) _pplr_Kd)
  (:pplr_Ki
   (&optional __pplr_Ki)
   (if __pplr_Ki (setq _pplr_Ki __pplr_Ki)) _pplr_Ki)
  (:pplr_Kp
   (&optional __pplr_Kp)
   (if __pplr_Kp (setq _pplr_Kp __pplr_Kp)) _pplr_Kp)
  (:pplr_Output
   (&optional __pplr_Output)
   (if __pplr_Output (setq _pplr_Output __pplr_Output)) _pplr_Output)
  (:pplr_Setpoint
   (&optional __pplr_Setpoint)
   (if __pplr_Setpoint (setq _pplr_Setpoint __pplr_Setpoint)) _pplr_Setpoint)
  (:ppud_timestamp
   (&optional __ppud_timestamp)
   (if __ppud_timestamp (setq _ppud_timestamp __ppud_timestamp)) _ppud_timestamp)
  (:ppud_Input
   (&optional __ppud_Input)
   (if __ppud_Input (setq _ppud_Input __ppud_Input)) _ppud_Input)
  (:ppud_Kd
   (&optional __ppud_Kd)
   (if __ppud_Kd (setq _ppud_Kd __ppud_Kd)) _ppud_Kd)
  (:ppud_Ki
   (&optional __ppud_Ki)
   (if __ppud_Ki (setq _ppud_Ki __ppud_Ki)) _ppud_Ki)
  (:ppud_Kp
   (&optional __ppud_Kp)
   (if __ppud_Kp (setq _ppud_Kp __ppud_Kp)) _ppud_Kp)
  (:ppud_Output
   (&optional __ppud_Output)
   (if __ppud_Output (setq _ppud_Output __ppud_Output)) _ppud_Output)
  (:ppud_Setpoint
   (&optional __ppud_Setpoint)
   (if __ppud_Setpoint (setq _ppud_Setpoint __ppud_Setpoint)) _ppud_Setpoint)
  (:yaw
   (&optional __yaw)
   (if __yaw (setq _yaw __yaw)) _yaw)
  (:pitch
   (&optional __pitch)
   (if __pitch (setq _pitch __pitch)) _pitch)
  (:roll
   (&optional __roll)
   (if __roll (setq _roll __roll)) _roll)
  (:timestamp
   (&optional __timestamp)
   (if __timestamp (setq _timestamp __timestamp)) _timestamp)
  (:tune_type
   (&optional __tune_type)
   (if __tune_type (setq _tune_type __tune_type)) _tune_type)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _H
    (send _H :serialization-length)
    ;; int16 _mpuData_AcX
    2
    ;; int16 _mpuData_AcY
    2
    ;; int16 _mpuData_AcZ
    2
    ;; uint32 _mpuData_timestamp
    4
    ;; int16 _mpuData_Tmp
    2
    ;; int16 _mpuData_GyX
    2
    ;; int16 _mpuData_GyY
    2
    ;; int16 _mpuData_GyZ
    2
    ;; int16 _mpuRAW_AcX
    2
    ;; int16 _mpuRAW_AcY
    2
    ;; int16 _mpuRAW_AcZ
    2
    ;; uint32 _mpuRAW_timestamp
    4
    ;; int16 _mpuRAW_Tmp
    2
    ;; int16 _mpuRAW_GyX
    2
    ;; int16 _mpuRAW_GyY
    2
    ;; int16 _mpuRAW_GyZ
    2
    ;; int16 _pingheight
    2
    ;; uint32 _ppfb_timestamp
    4
    ;; float64 _ppfb_Input
    8
    ;; float64 _ppfb_Kd
    8
    ;; float64 _ppfb_Ki
    8
    ;; float64 _ppfb_Kp
    8
    ;; float64 _ppfb_Output
    8
    ;; float64 _ppfb_Setpoint
    8
    ;; uint32 _pplr_timestamp
    4
    ;; float64 _pplr_Input
    8
    ;; float64 _pplr_Kd
    8
    ;; float64 _pplr_Ki
    8
    ;; float64 _pplr_Kp
    8
    ;; float64 _pplr_Output
    8
    ;; float64 _pplr_Setpoint
    8
    ;; uint32 _ppud_timestamp
    4
    ;; float64 _ppud_Input
    8
    ;; float64 _ppud_Kd
    8
    ;; float64 _ppud_Ki
    8
    ;; float64 _ppud_Kp
    8
    ;; float64 _ppud_Output
    8
    ;; float64 _ppud_Setpoint
    8
    ;; float32 _yaw
    4
    ;; float32 _pitch
    4
    ;; float32 _roll
    4
    ;; uint32 _timestamp
    4
    ;; int16 _tune_type
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _H
       (send _H :serialize s)
     ;; int16 _mpuData_AcX
       (write-word _mpuData_AcX s)
     ;; int16 _mpuData_AcY
       (write-word _mpuData_AcY s)
     ;; int16 _mpuData_AcZ
       (write-word _mpuData_AcZ s)
     ;; uint32 _mpuData_timestamp
       (write-long _mpuData_timestamp s)
     ;; int16 _mpuData_Tmp
       (write-word _mpuData_Tmp s)
     ;; int16 _mpuData_GyX
       (write-word _mpuData_GyX s)
     ;; int16 _mpuData_GyY
       (write-word _mpuData_GyY s)
     ;; int16 _mpuData_GyZ
       (write-word _mpuData_GyZ s)
     ;; int16 _mpuRAW_AcX
       (write-word _mpuRAW_AcX s)
     ;; int16 _mpuRAW_AcY
       (write-word _mpuRAW_AcY s)
     ;; int16 _mpuRAW_AcZ
       (write-word _mpuRAW_AcZ s)
     ;; uint32 _mpuRAW_timestamp
       (write-long _mpuRAW_timestamp s)
     ;; int16 _mpuRAW_Tmp
       (write-word _mpuRAW_Tmp s)
     ;; int16 _mpuRAW_GyX
       (write-word _mpuRAW_GyX s)
     ;; int16 _mpuRAW_GyY
       (write-word _mpuRAW_GyY s)
     ;; int16 _mpuRAW_GyZ
       (write-word _mpuRAW_GyZ s)
     ;; int16 _pingheight
       (write-word _pingheight s)
     ;; uint32 _ppfb_timestamp
       (write-long _ppfb_timestamp s)
     ;; float64 _ppfb_Input
       (sys::poke _ppfb_Input (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ppfb_Kd
       (sys::poke _ppfb_Kd (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ppfb_Ki
       (sys::poke _ppfb_Ki (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ppfb_Kp
       (sys::poke _ppfb_Kp (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ppfb_Output
       (sys::poke _ppfb_Output (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ppfb_Setpoint
       (sys::poke _ppfb_Setpoint (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; uint32 _pplr_timestamp
       (write-long _pplr_timestamp s)
     ;; float64 _pplr_Input
       (sys::poke _pplr_Input (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _pplr_Kd
       (sys::poke _pplr_Kd (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _pplr_Ki
       (sys::poke _pplr_Ki (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _pplr_Kp
       (sys::poke _pplr_Kp (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _pplr_Output
       (sys::poke _pplr_Output (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _pplr_Setpoint
       (sys::poke _pplr_Setpoint (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; uint32 _ppud_timestamp
       (write-long _ppud_timestamp s)
     ;; float64 _ppud_Input
       (sys::poke _ppud_Input (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ppud_Kd
       (sys::poke _ppud_Kd (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ppud_Ki
       (sys::poke _ppud_Ki (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ppud_Kp
       (sys::poke _ppud_Kp (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ppud_Output
       (sys::poke _ppud_Output (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ppud_Setpoint
       (sys::poke _ppud_Setpoint (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float32 _yaw
       (sys::poke _yaw (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _pitch
       (sys::poke _pitch (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _roll
       (sys::poke _roll (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint32 _timestamp
       (write-long _timestamp s)
     ;; int16 _tune_type
       (write-word _tune_type s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _H
     (send _H :deserialize buf ptr-) (incf ptr- (send _H :serialization-length))
   ;; int16 _mpuData_AcX
     (setq _mpuData_AcX (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _mpuData_AcY
     (setq _mpuData_AcY (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _mpuData_AcZ
     (setq _mpuData_AcZ (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint32 _mpuData_timestamp
     (setq _mpuData_timestamp (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int16 _mpuData_Tmp
     (setq _mpuData_Tmp (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _mpuData_GyX
     (setq _mpuData_GyX (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _mpuData_GyY
     (setq _mpuData_GyY (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _mpuData_GyZ
     (setq _mpuData_GyZ (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _mpuRAW_AcX
     (setq _mpuRAW_AcX (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _mpuRAW_AcY
     (setq _mpuRAW_AcY (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _mpuRAW_AcZ
     (setq _mpuRAW_AcZ (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint32 _mpuRAW_timestamp
     (setq _mpuRAW_timestamp (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int16 _mpuRAW_Tmp
     (setq _mpuRAW_Tmp (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _mpuRAW_GyX
     (setq _mpuRAW_GyX (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _mpuRAW_GyY
     (setq _mpuRAW_GyY (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _mpuRAW_GyZ
     (setq _mpuRAW_GyZ (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _pingheight
     (setq _pingheight (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint32 _ppfb_timestamp
     (setq _ppfb_timestamp (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _ppfb_Input
     (setq _ppfb_Input (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ppfb_Kd
     (setq _ppfb_Kd (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ppfb_Ki
     (setq _ppfb_Ki (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ppfb_Kp
     (setq _ppfb_Kp (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ppfb_Output
     (setq _ppfb_Output (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ppfb_Setpoint
     (setq _ppfb_Setpoint (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; uint32 _pplr_timestamp
     (setq _pplr_timestamp (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _pplr_Input
     (setq _pplr_Input (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _pplr_Kd
     (setq _pplr_Kd (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _pplr_Ki
     (setq _pplr_Ki (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _pplr_Kp
     (setq _pplr_Kp (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _pplr_Output
     (setq _pplr_Output (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _pplr_Setpoint
     (setq _pplr_Setpoint (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; uint32 _ppud_timestamp
     (setq _ppud_timestamp (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _ppud_Input
     (setq _ppud_Input (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ppud_Kd
     (setq _ppud_Kd (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ppud_Ki
     (setq _ppud_Ki (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ppud_Kp
     (setq _ppud_Kp (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ppud_Output
     (setq _ppud_Output (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ppud_Setpoint
     (setq _ppud_Setpoint (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float32 _yaw
     (setq _yaw (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _pitch
     (setq _pitch (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _roll
     (setq _roll (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint32 _timestamp
     (setq _timestamp (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int16 _tune_type
     (setq _tune_type (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get atom_esp_listener::alldata :md5sum-) "89b11db5299c2f38020d1ab5e96c3b97")
(setf (get atom_esp_listener::alldata :datatype-) "atom_esp_listener/alldata")
(setf (get atom_esp_listener::alldata :definition-)
      "Header H
int16  mpuData_AcX
int16  mpuData_AcY
int16  mpuData_AcZ
uint32  mpuData_timestamp
int16  mpuData_Tmp
int16  mpuData_GyX
int16  mpuData_GyY
int16  mpuData_GyZ

int16  mpuRAW_AcX
int16  mpuRAW_AcY
int16  mpuRAW_AcZ
uint32  mpuRAW_timestamp
int16  mpuRAW_Tmp
int16  mpuRAW_GyX
int16  mpuRAW_GyY
int16  mpuRAW_GyZ

int16  pingheight

uint32  ppfb_timestamp
float64  ppfb_Input
float64  ppfb_Kd
float64  ppfb_Ki
float64  ppfb_Kp
float64  ppfb_Output
float64  ppfb_Setpoint

uint32  pplr_timestamp
float64  pplr_Input
float64  pplr_Kd
float64  pplr_Ki
float64  pplr_Kp
float64  pplr_Output
float64  pplr_Setpoint

uint32  ppud_timestamp
float64  ppud_Input
float64  ppud_Kd
float64  ppud_Ki
float64  ppud_Kp
float64  ppud_Output
float64  ppud_Setpoint

float32  yaw
float32  pitch
float32  roll

uint32  timestamp
int16  tune_type

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

")



(provide :atom_esp_listener/alldata "89b11db5299c2f38020d1ab5e96c3b97")


