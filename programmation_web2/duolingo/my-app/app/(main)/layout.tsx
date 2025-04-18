import React from 'react'
import { Sidebar } from '@/components/sidebar';
import { Mobileheader } from '@/components/mobileheader';
type props = {
    children :React.ReactNode
}
function Mainlayout({children}: props) {
  return (
    <>
        <Mobileheader/>
        <Sidebar className='hidden lg:flex'/>
        <main className='h-full lg:pl-[256px] pt-[50px] lg:pt-0'>
            <div className='h-full max-w-[1056px] pt-6 mx-auto'>{children}</div>
        </main>
    </>
  )
}

export default Mainlayout;