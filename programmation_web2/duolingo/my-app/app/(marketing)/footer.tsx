import React from 'react'
import { Button } from '@/components/ui/button'
import Image from 'next/image'
export function Footer() {
  return (
    <footer className='h-20 w-full hidden lg:block border-t-2 border-slate-200 p-2'>
        <div className='max-w-screen-lg mx-auto flex items-center h-full justify-evenly'>
          <Button size={"lg"} variant={"ghost"} className='w-full'>
            <Image src={"/es.svg"} alt='Spanish' className='mr-4 rounded-md' width={40} height={32}/>
            Spanish
          </Button>

          <Button size={"lg"} variant={"ghost"} className='w-full'>
            <Image src={"/fr.svg"} alt='French' className='mr-4 rounded-md' width={40} height={32}/>
            French
          </Button>

          <Button size={"lg"} variant={"ghost"} className='w-full'>
            <Image src={"/jp.svg"} alt='Japenese' className='mr-4 rounded-md' width={40} height={32}/>
            Japenese
          </Button>

          <Button size={"lg"} variant={"ghost"} className='w-full'>
            <Image src={"/it.svg"} alt='Italian' className='mr-4 rounded-md' width={40} height={32}/>
            Italian
          </Button>
        </div>
    </footer>

  )
};