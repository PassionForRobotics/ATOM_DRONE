
(cl:in-package :asdf)

(defsystem "atom_esp_joy-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "joydata" :depends-on ("_package_joydata"))
    (:file "_package_joydata" :depends-on ("_package"))
  ))