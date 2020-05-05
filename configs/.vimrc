"========== Plugins =========="
call plug#begin('~/.vim/plugged')

Plug 'liuchengxu/space-vim-dark'
Plug 'ayu-theme/ayu-vim'
Plug 'itchyny/lightline.vim'
Plug 'preservim/nerdtree'
Plug 'preservim/nerdcommenter'
Plug 'tpope/vim-fugitive'
Plug 'prettier/vim-prettier', { 'do': 'yarn install' }
Plug 'SirVer/ultisnips'
Plug 'lervag/vimtex'
Plug 'cohama/lexima.vim'
Plug 'mattn/emmet-vim'

call plug#end()

"========== Colorcheme =========="
let ayucolor="mirage"
colorscheme ayu
"colorscheme space-vim-dark
"let g:lightline = {'colorscheme': 'deus'}

"hi Normal     ctermbg=NONE guibg=NONE
hi LineNr     ctermbg=NONE guibg=NONE
hi SignColumn ctermbg=NONE guibg=NONE

if(has("termguicolors"))
  set termguicolors
endif
highlight MatchParen ctermbg=blue guibg=darkgreen
"========== Settings =========="
set shiftwidth=4
set autoindent
set smartindent
set tabstop=4
set number
set laststatus=2
set noshowmode
set splitright
set showcmd
set timeoutlen=1000 ttimeoutlen=0
let NERDTreeShowHidden=1
autocmd StdinReadPre * let s:std_in=2
autocmd VimEnter * if argc() == 0 && !exists("s:std_in") | NERDTree | endif
set autoread
set autowrite
set nobackup
set nowb
set noswapfile
set backupdir=~/tmp,/tmp
set backupcopy=yes
set backupskip=/tmp/*,$TMPDIR/*,$TMP/*,$TEMP/*
set directory=/tmp
filetype plugin on
set clipboard=unnamedplus
set autoindent
set si
set cindent
nnoremap <C-k> :bnext<CR>
let g:NERDSpaceDelims = 1
let g:NERDTrimTrailingWhitespace = 1
let g:NERDToggleCheckAllLines = 1
map <C-C> <leader>cb
map <C-X> <leader>cu
nmap ? :NERDTreeToggle<CR>
let g:NERDTreeQuitOnOpen = 1
let g:NERDTreeWinPos = "left"
"nnoremap x "_x
"nnoremap d "_d
"nnoremap D "_D
"vnoremap d "_d
"nnoremap <leader>d ""d
"nnoremap <leader>D ""D
"vnoremap <leader>d ""d
set encoding=utf-8
set expandtab
set softtabstop=4
let g:UltiSnipsExpandTrigger="<tab>"
let g:UltiSnipsJumpForwardTrigger="<c-b>"
let g:UltiSnipsJumpBackwardTrigger="<c-z>"
let g:tex_flavor = 'latex'
let g:vimtex_view_general_viewer = 'okular'
let g:vimtex_quickfix_mode=0
map C :tabp<CR>
map V :tabn<CR>
map X :tabclose<CR>
"autocmd BufWinEnter * NERDTreeMirror
"========== CP config =========="
map <F3> :%y+<CR>
map <F4> :vert term<CR>
map <F8> :w <bar> !echo "===== [COMPILING IN C++98] =====" && g++ "%:p" -O2 -std=c++98 -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -DLOCAL<CR>
map <F9> :w <bar> !echo "===== [COMPILING IN C++17] =====" && g++ "%:p" -O2 -std=c++17 -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -DLOCAL<CR>
map <F10> :!echo "===== [RUNNING: "%:t:r"] =====" && ./a.out<CR>
map <F5> :w <bar> !cf submit "https://codeforces.com/contest/""%:p:h:t""/problem/""%:t:r" -f "%:t"<CR>
map <F2> :w <bar> !acedit --run "%:p" -c "%:p:h:t" -p "%:t:r"<CR>
map <F6> :!cf sid<CR>

function AddTemplate(tmpl_file)
    exe "0read " . a:tmpl_file
    "let substDict = {}
    "let substDict["in"] = expand("%:t:r").".inp"
    "let substDict["out"] = expand("%:t:r").".out"
    "exe '%s/<<\([^>]*\)>>/\=substDict[submatch(1)]/g'
    8
endfunction

autocmd BufNewFile *.cpp call AddTemplate("~/template.cpp")
autocmd BufRead *.cpp if getfsize(expand('%'))==0|call AddTemplate("~/template.cpp")

"========== EOF =========="

