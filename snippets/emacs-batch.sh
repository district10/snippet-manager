##          ;;; File: emacs-format-file
##          ;;; Stan Warford
##          ;;; 17 May 2006
##
##          (defun emacs-format-function ()
##             "Format the whole buffer."
##             (c-set-style "stroustrup")
##             (indent-region (point-min) (point-max) nil)
##             (untabify (point-min) (point-max))
##             (save-buffer)
##          )
emacs -batch file-to-indent -l ~/bin/emacs-format-file -f emacs-format-function

emacs \
    --batch file.md \
    --eval "(org-mode)" \
    --eval "(setq org-html-htmlize-output-type 'css)" \
    --eval '(setq org-html-htmlize-font-prefix "org-")' \
    --eval '(org-html-export-to-html)'
