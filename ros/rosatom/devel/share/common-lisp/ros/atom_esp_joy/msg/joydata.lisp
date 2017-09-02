; Auto-generated. Do not edit!


(cl:in-package atom_esp_joy-msg)


;//! \htmlinclude joydata.msg.html

(cl:defclass <joydata> (roslisp-msg-protocol:ros-message)
  ((X
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
  "9ea973d7e29e9a09bf4c38bea786a98f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'joydata)))
  "Returns md5sum for a message object of type 'joydata"
  "9ea973d7e29e9a09bf4c38bea786a98f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<joydata>)))
  "Returns full string definition for message of type '<joydata>"
  (cl:format cl:nil "int16 X~%int16 Y~%int16 Z~%int16 S~%uint16 buttons # F1,B2,3,4,5,6,7,8,9,10,11,12,H1,2,3,4~%# 0000 0~%# 0001 1~%# 0010 2~%# 0011 3~%# 0100 4~%# 0101 5~%# 0110 6~%# 0111 7~%# 1000 8~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'joydata)))
  "Returns full string definition for message of type 'joydata"
  (cl:format cl:nil "int16 X~%int16 Y~%int16 Z~%int16 S~%uint16 buttons # F1,B2,3,4,5,6,7,8,9,10,11,12,H1,2,3,4~%# 0000 0~%# 0001 1~%# 0010 2~%# 0011 3~%# 0100 4~%# 0101 5~%# 0110 6~%# 0111 7~%# 1000 8~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <joydata>))
  (cl:+ 0
     2
     2
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <joydata>))
  "Converts a ROS message object to a list"
  (cl:list 'joydata
    (cl:cons ':X (X msg))
    (cl:cons ':Y (Y msg))
    (cl:cons ':Z (Z msg))
    (cl:cons ':S (S msg))
    (cl:cons ':buttons (buttons msg))
))
