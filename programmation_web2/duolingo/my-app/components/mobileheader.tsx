import React from 'react'
import { MobileSidebar } from './mobileSidebar'

export function Mobileheader() {
  return (
    <nav className='h-[50px] px-6 w-full flex items-center bg-green-500 fixed lg:hidden border-b  top-0 z-50'>
        <MobileSidebar/>
    </nav>
  )
}