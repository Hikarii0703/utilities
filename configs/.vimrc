"========== Plugins =========="
call plug#begin('~/.vim/plugged')

Plug 'itchyny/lightline.vim'
Plug 'preservim/nerdcommenter'
Plug 'SirVer/ultisnips'
Plug 'cocopon/iceberg.vim'
Plug 'cohama/lexima.vim'

call plug#end()

"========== Colorcheme =========="
colorscheme iceberg

let g:lightline = {'colorscheme': 'deus'}

if(has("termguicolors"))
  set termguicolors
endif

set background=dark

"========== Settings =========="
" indentation
set shiftwidth=4
set autoindent
set smartindent
set cindent
set tabstop=4
set expandtab
set softtabstop=4

" misc vim config
set laststatus=2
set noshowmode
set splitright
set showcmd
set timeoutlen=1000 ttimeoutlen=0
set number
set encoding=utf-8

" don't clear clipboard on exit
autocmd VimLeave * call system("xsel -ib", getreg('+'))

" no backups
set autoread
set autowrite
set nobackup
set nowb
set noswapfile
set backupdir=~/tmp,/tmp
set backupcopy=yes
set backupskip=/tmp/*,$TMPDIR/*,$TMP/*,$TEMP/*
set directory=/tmp

" nerd commenter
let g:NERDSpaceDelims = 1
let g:NERDTrimTrailingWhitespace = 1
let g:NERDToggleCheckAllLines = 1
map <C-c> <leader>cb
map <C-x> <leader>cu

" ultisnips
let g:UltiSnipsExpandTrigger="<tab>"
let g:UltiSnipsJumpForwardTrigger="<c-b>"
let g:UltiSnipsJumpBackwardTrigger="<c-z>"

"========== CP config =========="
" (some commands requre having necessary files)
" F3: copy the whole file content to clipboard
" F4: check code with example test cases on Codeforces
" F5: submit code to Codeforces
" F6: open the latest submission
" F8: compile code with C++98
" F9: compile code with C++17
" F10: run compiled executable

map <F3> :%y+<CR>
map <F4> :w <bar> !acedit --run "%:p" -c "%:p:h:t" -p "%:t:r"<CR>
map <F5> :w <bar> !cf submit "https://codeforces.com/contest/""%:p:h:t""/problem/""%:t:r" -f "%:t"<CR>
map <F6> :!cf sid<CR>
map <F8> :w <bar> !clear && contest "%:t" 98<CR>
map <F9> :w <bar> !clear && contest "%:t"<CR>
map <F10> :!run_contest "%:t"<CR>

" add template to cpp file
function AddTemplate(tmpl_file)
    exe "0read " . a:tmpl_file
    "let substDict = {}
    "let substDict["in"] = expand("%:t:r").".inp"
    "let substDict["out"] = expand("%:t:r").".out"
    "exe '%s/<<\([^>]*\)>>/\=substDict[submatch(1)]/g'
    8
endfunction

let dir="~/template.cpp"
autocmd BufNewFile *.cpp call AddTemplate(dir)
autocmd BufRead *.cpp if getfsize(expand('%'))==0|call AddTemplate(dir)
"========== EOF =========="


