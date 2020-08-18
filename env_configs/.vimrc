"========== Plugins =========="
call plug#begin('~/.vim/plugged')
Plug 'itchyny/lightline.vim'
Plug 'preservim/nerdcommenter'
Plug 'SirVer/ultisnips'
Plug 'rakr/vim-one'
call plug#end()
"========== Colorcheme =========="
set termguicolors
syntax enable
colorscheme one
set background=light
let g:lightline = {'colorscheme': 'one'}
"========== Settings =========="
" indentation
filetype plugin indent on
set shiftwidth=4
set tabstop=4
set expandtab
set softtabstop=4
set cinoptions+=L0

" misc vim config
set laststatus=2
set noshowmode
set number
set encoding=utf-8

" don't clear clipboard on exit
set clipboard=unnamedplus
autocmd VimLeave * call system("xsel -ib", getreg('+'))

" no backups
set nobackup
set noswapfile

" nerd commenter
let g:NERDSpaceDelims = 1
map <C-c> <leader>cb
map <C-x> <leader>cu

" ultisnips
let g:UltiSnipsExpandTrigger="<tab>"

" manual autocomplete
inoremap " ""<left>
inoremap ' ''<left>
inoremap ( ()<left>
inoremap [ []<left>
inoremap { {}<left>
inoremap {<CR> {<CR>}<ESC>O
inoremap {;<CR> {<CR>};<ESC>O

"========== CP config =========="
map <F3> :%y+<CR>
map <F9> :w <bar> !contest "%:t"<CR>
map <F10> :!run_contest "%:t"<CR>

" add template to cpp file
function AddTemplate(tmpl_file)
    exe "0read " . a:tmpl_file
    6
endfunction

autocmd BufNewFile *.cpp call AddTemplate("~/template.cpp")
"========== EOF =========="

