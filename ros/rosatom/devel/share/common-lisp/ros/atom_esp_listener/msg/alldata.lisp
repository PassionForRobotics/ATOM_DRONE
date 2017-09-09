; Auto-generated. Do not edit!


(cl:in-package atom_esp_listener-msg)


;//! \htmlinclude alldata.msg.html

(cl:defclass <alldata> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (mpuRAW
    :reader mpuRAW
    :initarg :mpuRAW
    :type atom_esp_listener-msg:mpudata
    :initform (cl:make-instance 'atom_esp_listener-msg:mpudata))
   (pingheight
    :reader pingheight
    :initarg :pingheight
    :type cl:float
    :initform 0.0)
   (ppfb
    :reader ppfb
    :initarg :ppfb
    :type atom_esp_listener-msg:PID_Tune_Params
    :initform (cl:make-instance 'atom_esp_listener-msg:PID_Tune_Params))
   (pplr
    :reader pplr
    :initarg :pplr
    :type atom_esp_listener-msg:PID_Tune_Params
    :initform (cl:make-instance 'atom_esp_listener-msg:PID_Tune_Params))
   (ppud
    :reader ppud
    :initarg :ppud
    :type atom_esp_listener-msg:PID_Tune_Params
    :initform (cl:make-instance 'atom_esp_listener-msg:PID_Tune_Params))
   (yaw
    :reader yaw
    :initarg :yaw
    :type cl:float
    :initform 0.0)
   (pitch
    :reader pitch
    :initarg :pitch
    :type cl:float
    :initform 0.0)
   (roll
    :reader roll
    :initarg :roll
    :type cl:float
    :initform 0.0)
   (timestamp
    :reader timestamp
    :initarg :timestamp
    :type cl:integer
    :initform 0)
   (tune_type
    :reader tune_type
    :initarg :tune_type
    :type cl:fixnum
    :initform 0)
   (profiled_loop
    :reader profiled_loop
    :initarg :profiled_loop
    :type atom_esp_listener-msg:Profiler_data
    :initform (cl:make-instance 'atom_esp_listener-msg:Profiler_data))
   (profiled_mpu
    :reader profiled_mpu
    :initarg :profiled_mpu
    :type atom_esp_listener-msg:Profiler_data
    :initform (cl:make-instance 'atom_esp_listener-msg:Profiler_data))
   (profiled_wifi
    :reader profiled_wifi
    :initarg :profiled_wifi
    :type atom_esp_listener-msg:Profiler_data
    :initform (cl:make-instance 'atom_esp_listener-msg:Profiler_data))
   (profiled_steer
    :reader profiled_steer
    :initarg :profiled_steer
    :type atom_esp_listener-msg:Profiler_data
    :initform (cl:make-instance 'atom_esp_listener-msg:Profiler_data)))
)

(cl:defclass alldata (<alldata>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <alldata>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'alldata)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name atom_esp_listener-msg:<alldata> is deprecated: use atom_esp_listener-msg:alldata instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:header-val is deprecated.  Use atom_esp_listener-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'mpuRAW-val :lambda-list '(m))
(cl:defmethod mpuRAW-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:mpuRAW-val is deprecated.  Use atom_esp_listener-msg:mpuRAW instead.")
  (mpuRAW m))

(cl:ensure-generic-function 'pingheight-val :lambda-list '(m))
(cl:defmethod pingheight-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:pingheight-val is deprecated.  Use atom_esp_listener-msg:pingheight instead.")
  (pingheight m))

(cl:ensure-generic-function 'ppfb-val :lambda-list '(m))
(cl:defmethod ppfb-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:ppfb-val is deprecated.  Use atom_esp_listener-msg:ppfb instead.")
  (ppfb m))

(cl:ensure-generic-function 'pplr-val :lambda-list '(m))
(cl:defmethod pplr-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:pplr-val is deprecated.  Use atom_esp_listener-msg:pplr instead.")
  (pplr m))

(cl:ensure-generic-function 'ppud-val :lambda-list '(m))
(cl:defmethod ppud-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:ppud-val is deprecated.  Use atom_esp_listener-msg:ppud instead.")
  (ppud m))

(cl:ensure-generic-function 'yaw-val :lambda-list '(m))
(cl:defmethod yaw-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:yaw-val is deprecated.  Use atom_esp_listener-msg:yaw instead.")
  (yaw m))

(cl:ensure-generic-function 'pitch-val :lambda-list '(m))
(cl:defmethod pitch-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:pitch-val is deprecated.  Use atom_esp_listener-msg:pitch instead.")
  (pitch m))

(cl:ensure-generic-function 'roll-val :lambda-list '(m))
(cl:defmethod roll-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:roll-val is deprecated.  Use atom_esp_listener-msg:roll instead.")
  (roll m))

(cl:ensure-generic-function 'timestamp-val :lambda-list '(m))
(cl:defmethod timestamp-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:timestamp-val is deprecated.  Use atom_esp_listener-msg:timestamp instead.")
  (timestamp m))

(cl:ensure-generic-function 'tune_type-val :lambda-list '(m))
(cl:defmethod tune_type-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:tune_type-val is deprecated.  Use atom_esp_listener-msg:tune_type instead.")
  (tune_type m))

(cl:ensure-generic-function 'profiled_loop-val :lambda-list '(m))
(cl:defmethod profiled_loop-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:profiled_loop-val is deprecated.  Use atom_esp_listener-msg:profiled_loop instead.")
  (profiled_loop m))

(cl:ensure-generic-function 'profiled_mpu-val :lambda-list '(m))
(cl:defmethod profiled_mpu-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:profiled_mpu-val is deprecated.  Use atom_esp_listener-msg:profiled_mpu instead.")
  (profiled_mpu m))

(cl:ensure-generic-function 'profiled_wifi-val :lambda-list '(m))
(cl:defmethod profiled_wifi-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:profiled_wifi-val is deprecated.  Use atom_esp_listener-msg:profiled_wifi instead.")
  (profiled_wifi m))

(cl:ensure-generic-function 'profiled_steer-val :lambda-list '(m))
(cl:defmethod profiled_steer-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:profiled_steer-val is deprecated.  Use atom_esp_listener-msg:profiled_steer instead.")
  (profiled_steer m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <alldata>) ostream)
  "Serializes a message object of type '<alldata>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'mpuRAW) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pingheight))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'ppfb) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pplr) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'ppud) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'yaw))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pitch))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'roll))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tune_type)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tune_type)) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'profiled_loop) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'profiled_mpu) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'profiled_wifi) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'profiled_steer) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <alldata>) istream)
  "Deserializes a message object of type '<alldata>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'mpuRAW) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pingheight) (roslisp-utils:decode-single-float-bits bits)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'ppfb) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pplr) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'ppud) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'yaw) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pitch) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'roll) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tune_type)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tune_type)) (cl:read-byte istream))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'profiled_loop) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'profiled_mpu) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'profiled_wifi) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'profiled_steer) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<alldata>)))
  "Returns string type for a message object of type '<alldata>"
  "atom_esp_listener/alldata")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'alldata)))
  "Returns string type for a message object of type 'alldata"
  "atom_esp_listener/alldata")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<alldata>)))
  "Returns md5sum for a message object of type '<alldata>"
  "9f657d5dee01c22ca305fb4d2b9139bc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'alldata)))
  "Returns md5sum for a message object of type 'alldata"
  "9f657d5dee01c22ca305fb4d2b9139bc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<alldata>)))
  "Returns full string definition for message of type '<alldata>"
  (cl:format cl:nil "Header header~%#int16  mpuData_AcX~%#int16  mpuData_AcY~%#int16  mpuData_AcZ~%#uint32  mpuData_timestamp~%#int16  mpuData_Tmp~%#int16  mpuData_GyX~%#int16  mpuData_GyY~%#int16  mpuData_GyZ~%~%mpudata mpuRAW~%#int16  mpuRAW_AcX~%#int16  mpuRAW_AcY~%#int16  mpuRAW_AcZ~%#uint32  mpuRAW_timestamp~%#int16  mpuRAW_Tmp~%#int16  mpuRAW_GyX~%#int16  mpuRAW_GyY~%#int16  mpuRAW_GyZ~%~%float32  pingheight~%~%PID_Tune_Params ppfb~%#uint32  ppfb_timestamp~%#float64  ppfb_Input~%#float64  ppfb_Kd~%#float64  ppfb_Ki~%#float64  ppfb_Kp~%#float64  ppfb_Output~%#float64  ppfb_Setpoint~%~%PID_Tune_Params pplr~%#uint32  pplr_timestamp~%#float64  pplr_Input~%#float64  pplr_Kd~%#float64  pplr_Ki~%#float64  pplr_Kp~%#float64  pplr_Output~%#float64  pplr_Setpoint~%~%PID_Tune_Params ppud~%#uint32  ppud_timestamp~%#float64  ppud_Input~%#float64  ppud_Kd~%#float64  ppud_Ki~%#float64  ppud_Kp~%#float64  ppud_Output~%#float64  ppud_Setpoint~%~%float32  yaw~%float32  pitch~%float32  roll~%~%uint32  timestamp~%uint16  tune_type~%~%Profiler_data profiled_loop~%Profiler_data profiled_mpu~%Profiler_data profiled_wifi~%Profiler_data profiled_steer~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: atom_esp_listener/mpudata~%Header header~%uint32 timestamp~%int16  AcX~%int16  AcY~%int16  AcZ~%int16  Tmp~%int16  GyX~%int16  GyY~%int16  GyZ~%~%================================================================================~%MSG: atom_esp_listener/PID_Tune_Params~%Header header~%uint32  timestamp~%float64 Setpoint~%float64 Input~%float64 Output~%float64 Kd~%float64 Ki~%float64 Kp~%~%================================================================================~%MSG: atom_esp_listener/Profiler_data~%Header  header~%uint32  timestamp~%uint16  averageIterationCount~%float32 averageTime # micros~%float32 averageTime2 # micros~%uint32  averageTick~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'alldata)))
  "Returns full string definition for message of type 'alldata"
  (cl:format cl:nil "Header header~%#int16  mpuData_AcX~%#int16  mpuData_AcY~%#int16  mpuData_AcZ~%#uint32  mpuData_timestamp~%#int16  mpuData_Tmp~%#int16  mpuData_GyX~%#int16  mpuData_GyY~%#int16  mpuData_GyZ~%~%mpudata mpuRAW~%#int16  mpuRAW_AcX~%#int16  mpuRAW_AcY~%#int16  mpuRAW_AcZ~%#uint32  mpuRAW_timestamp~%#int16  mpuRAW_Tmp~%#int16  mpuRAW_GyX~%#int16  mpuRAW_GyY~%#int16  mpuRAW_GyZ~%~%float32  pingheight~%~%PID_Tune_Params ppfb~%#uint32  ppfb_timestamp~%#float64  ppfb_Input~%#float64  ppfb_Kd~%#float64  ppfb_Ki~%#float64  ppfb_Kp~%#float64  ppfb_Output~%#float64  ppfb_Setpoint~%~%PID_Tune_Params pplr~%#uint32  pplr_timestamp~%#float64  pplr_Input~%#float64  pplr_Kd~%#float64  pplr_Ki~%#float64  pplr_Kp~%#float64  pplr_Output~%#float64  pplr_Setpoint~%~%PID_Tune_Params ppud~%#uint32  ppud_timestamp~%#float64  ppud_Input~%#float64  ppud_Kd~%#float64  ppud_Ki~%#float64  ppud_Kp~%#float64  ppud_Output~%#float64  ppud_Setpoint~%~%float32  yaw~%float32  pitch~%float32  roll~%~%uint32  timestamp~%uint16  tune_type~%~%Profiler_data profiled_loop~%Profiler_data profiled_mpu~%Profiler_data profiled_wifi~%Profiler_data profiled_steer~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: atom_esp_listener/mpudata~%Header header~%uint32 timestamp~%int16  AcX~%int16  AcY~%int16  AcZ~%int16  Tmp~%int16  GyX~%int16  GyY~%int16  GyZ~%~%================================================================================~%MSG: atom_esp_listener/PID_Tune_Params~%Header header~%uint32  timestamp~%float64 Setpoint~%float64 Input~%float64 Output~%float64 Kd~%float64 Ki~%float64 Kp~%~%================================================================================~%MSG: atom_esp_listener/Profiler_data~%Header  header~%uint32  timestamp~%uint16  averageIterationCount~%float32 averageTime # micros~%float32 averageTime2 # micros~%uint32  averageTick~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <alldata>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'mpuRAW))
     4
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'ppfb))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pplr))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'ppud))
     4
     4
     4
     4
     2
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'profiled_loop))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'profiled_mpu))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'profiled_wifi))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'profiled_steer))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <alldata>))
  "Converts a ROS message object to a list"
  (cl:list 'alldata
    (cl:cons ':header (header msg))
    (cl:cons ':mpuRAW (mpuRAW msg))
    (cl:cons ':pingheight (pingheight msg))
    (cl:cons ':ppfb (ppfb msg))
    (cl:cons ':pplr (pplr msg))
    (cl:cons ':ppud (ppud msg))
    (cl:cons ':yaw (yaw msg))
    (cl:cons ':pitch (pitch msg))
    (cl:cons ':roll (roll msg))
    (cl:cons ':timestamp (timestamp msg))
    (cl:cons ':tune_type (tune_type msg))
    (cl:cons ':profiled_loop (profiled_loop msg))
    (cl:cons ':profiled_mpu (profiled_mpu msg))
    (cl:cons ':profiled_wifi (profiled_wifi msg))
    (cl:cons ':profiled_steer (profiled_steer msg))
))
