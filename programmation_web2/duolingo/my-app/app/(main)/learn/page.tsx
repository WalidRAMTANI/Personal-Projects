import React from 'react'
import { Stickywrapper } from '@/components/stickywrapper'
import { Feedwrapper } from '@/components/feedwrappers'
import { Header } from './Header'
import { Userprogress } from '@/components/Userprogress'
function page() {
  return (
    <div className='flex flex-row-reverse gap-[48px] px-6'>
        <Stickywrapper>
          <Userprogress ActiveCourse={{ImageSrc: "/jp.svg", title:"Japenese"}} points = {100} hearts={5} HasActiveSubscription={false}/>
        </Stickywrapper>
        <Feedwrapper>
          <Header title="Japenese"/>
          <div>
            <div className='h-[500px] bg-blue-500 my-[20px]'></div>
            <div className='h-[500px] bg-blue-500 my-[20px]'></div>
            <div className='h-[500px] bg-blue-500 my-[20px]'></div>
            <div className='h-[500px] bg-blue-500 my-[20px]'></div>
            <div className='h-[500px] bg-blue-500 my-[20px]'></div>
            <div className='h-[500px] bg-blue-500 my-[20px]'></div>
            <div className='h-[500px] bg-blue-500 my-[20px]'></div>
            <div className='h-[500px] bg-blue-500 my-[20px]'></div>
            <div className='h-[500px] bg-blue-500 my-[20px]'></div>
            
          </div>
        </Feedwrapper>
    </div>
  )
}

export default page