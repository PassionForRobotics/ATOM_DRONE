; Auto-generated. Do not edit!


(cl:in-package atom_esp_joy-msg)


;//! \htmlinclude joydata.msg.html

(cl:defclass <joydata> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (X
    :reader X
    :initarg :X
    :type cl:fixnum
    :initform 0)
   (Y
    :reader Y
    :initarg :Y
    :type cl:fixnum
    :initform 0)
   (Z
    :reader Z
    :initarg :Z
    :type cl:fixnum
    :initform 0)
   (S
    :reader S
    :initarg :S
    :type cl:fixnum
    :initform 0)
   (buttons
    :reader buttons
    :initarg :buttons
    :type cl:fixnum
    :initform 0))
)

(cl:defclass joydata (<joydata>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <joydata>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'joydata)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name atom_esp_joy-msg:<joydata> is deprecated: use atom_esp_joy-msg:joydata instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <joydata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_joy-msg:header-val is deprecated.  Use atom_esp_joy-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'X-val :lambda-list '(m))
(cl:defmethod X-val ((m <joydata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_joy-msg:X-val is deprecated.  Use atom_esp_joy-msg:X instead.")
  (X m))

(cl:ensure-generic-function 'Y-val :lambda-list '(m))
(cl:defmethod Y-val ((m <joydata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_joy-msg:Y-val is deprecated.  Use atom_esp_joy-msg:Y instead.")
  (Y m))

(cl:ensure-generic-function 'Z-val :lambda-list '(m))
(cl:defmethod Z-val ((m <joydata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_joy-msg:Z-val is deprecated.  Use atom_esp_joy-msg:Z instead.")
  (Z m))

(cl:ensure-generic-function 'S-val :lambda-list '(m))
(cl:defmethod S-val ((m <joydata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_joy-msg:S-val is deprecated.  Use atom_esp_joy-msg:S instead.")
  (S m))

(cl:ensure-generic-function 'buttons-val :lambda-list '(m))
(cl:defmethod buttons-val ((m <joydata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_joy-msg:buttons-val is deprecated.  Use atom_esp_joy-msg:buttons instead.")
  (buttons m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <joydata>) ostream)
  "Serializes a message object of type '<joydata>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'X)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'Y)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'Z)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'S)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'buttons)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'buttons)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <joydata>) istream)
  "Deserializes a message object of type '<joydata>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'X) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Y) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Z) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'S) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'buttons)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'buttons)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<joydata>)))
  "Returns string type for a message object of type '<joydata>"
  "atom_esp_joy/joydata")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'joydata)))
  "Returns string type for a message object of type 'joydata"
  "atom_esp_joy/joydata")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<joydata>)))
  "Returns md5sum for a message object of type '<joydata>"
  "a8d766a6e235fd7ad875a4a557990e38")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'joydata)))
  "Returns md5sum for a message object of type 'joydata"
  "a8d766a6e235fd7ad875a4a557990e38")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<joydata>)))
  "Returns full string definition for message of type '<joydata>"
  (cl:format cl:nil "Header header~%int16 X~%int16 Y~%int16 Z~%int16 S~%uint16 buttons # MSB F1,B2,3,4,5,6,7,8,9,10,11,12,H1,2,3,4 LSB~%# 0000 0~%# 0001 1~%# 0010 2~%# 0011 3~%# 0100 4~%# 0101 5~%# 0110 6~%# 0111 7~%# 1000 8~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'joydata)))
  "Returns full string definition for message of type 'joydata"
  (cl:format cl:nil "Header header~%int16 X~%int16 Y~%int16 Z~%int16 S~%uint16 buttons # MSB F1,B2,3,4,5,6,7,8,9,10,11,12,H1,2,3,4 LSB~%# 0000 0~%# 0001 1~%# 0010 2~%# 0011 3~%# 0100 4~%# 0101 5~%# 0110 6~%# 0111 7~%# 1000 8~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <joydata>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     2
     2
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <joydata>))
  "Converts a ROS message object to a list"
  (cl:list 'joydata
    (cl:cons ':header (header msg))
    (cl:cons ':X (X msg))
    (cl:cons ':Y (Y msg))
    (cl:cons ':Z (Z msg))
    (cl:cons ':S (S msg))
    (cl:cons ':buttons (buttons msg))
))
